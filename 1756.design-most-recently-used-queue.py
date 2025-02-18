#
# @lc app=leetcode id=1756 lang=python3
#
# [1756] Design Most Recently Used Queue
#
from collections import deque
import math
from typing import *

# @lc code=start
class BinaryIndexedTree:
    # Fenwick tree
    def __init__(self, n):
        self.nums = [0] * (n + 1)

    def sum(self, k):
        ans = 0
        while k > 0:
            ans += self.nums[k]
            k -= (k & -k)
        return ans
    
    def add(self, k, x):
        k += 1
        while k < len(self.nums):
            self.nums[k] += x
            k += (k & -k)

# Square root decomposition + bucket sort?
# S: O(n)
class MRUQueue:
    # T: O(n)
    def __init__(self, n: int):
        # We're going to break up the numbers into buckets of size `sqrt(n)`.
        # Ceil because even if the bucket won't be full, we need the bucket
        # to store whatever numbers are there, e.g.
        # n = 8. We need 3 buckets: [1,2,3]  [4,5,6]  [7,8]
        # sqrt(8) is 2.82.. but we need 3 buckets.
        self.bucket_sz = math.ceil(math.sqrt(n))
        self.buckets: List[Deque[int]] = []   # each bucket is a queue

        nums = list(range(1, n + 1))
        # Break up the numbers into chunks of size sqrt(n).
        chunks = [nums[i: i + self.bucket_sz] for i in range(0, len(nums), self.bucket_sz)]

        for chunk in chunks:
            self.buckets.append(deque(chunk))

    # T: O(sqrt(n))
    def fetch(self, k: int) -> int:
        k -= 1  # k is 1-indexed
        bucket_idx = k // self.bucket_sz
        num_idx = k % self.bucket_sz  # index in the bucket
        bucket = self.buckets[bucket_idx]
        target_num = bucket[num_idx]

        # Remove the target number by re-creating the bucket without it
        new_bucket = deque()
        for i, num in enumerate(bucket):
            if i != num_idx:
                new_bucket.append(num)
        self.buckets[bucket_idx] = new_bucket

        # Append the target num to the tail.
        self.buckets[-1].append(target_num)

        # For this bucket and each subsequent ones, move down 1 element
        # to fill the gap of the moved target number.
        for b in range(bucket_idx, len(self.buckets) - 1):
            left_bucket = self.buckets[b]
            right_bucket = self.buckets[b + 1]
            left_bucket.append(right_bucket.popleft())

        return target_num
        


# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)
# @lc code=end

