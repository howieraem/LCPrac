#
# @lc app=leetcode id=315 lang=python3
#
# [315] Count of Smaller Numbers After Self
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n * log(n)) recursion and tmp array
    def countSmaller(self, nums: List[int]) -> List[int]:
        """
        Based on merge sort. To record the result, we need to 
        keep the index of each number in the original array. 
        Instead of sorting the number in `nums`, we sort the 
        indices of each number, so that `indices` end up with 
        argsort(nums).
        """
        n = len(nums)
        indices = list(range(n))
        res = [0] * n

        def merge_argsort(l: int, r: int):
            if l >= r:
                return
            m = l + ((r - l) >> 1)
            merge_argsort(l, m)
            merge_argsort(m + 1, r)
            merge(l, m, m + 1, r)

        def merge(l1: int, r1: int, l2: int, r2: int):
            nonlocal res, indices
            tmp_indices = [0] * (r2 - l1 + 1)
            cnt = 0  # record how many numbers from the right subarray we have added
            p = 0
            start = l1
            while l1 <= r1 and l2 <= r2:
                if nums[indices[l1]] > nums[indices[l2]]:
                    # The number on the right is smaller.
                    # When we move a number from the right subarray into the new sorted array, 
                    # we increment count.
                    cnt += 1
                    tmp_indices[p] = indices[l2]
                    l2 += 1
                else:
                    # The number on the left is smaller.
                    # When we move a number from the left subarray into the new sorted array, 
                    # we increase res[index of the number] by count.
                    res[indices[l1]] += cnt
                    tmp_indices[p] = indices[l1]
                    l1 += 1
                p += 1
            
            # Finish the unprocessed subarray, either left or right
            while l1 <= r1:
                res[indices[l1]] += cnt
                tmp_indices[p] = indices[l1]
                l1 += 1
                p += 1
            while l2 <= r2:
                tmp_indices[p] = indices[l2]
                l2 += 1
                p += 1
            
            # Update the argsort indices for the range [l1, r2)
            for i in range(len(tmp_indices)):
                indices[start + i] = tmp_indices[i]

        merge_argsort(0, n - 1)
        return res

# @lc code=end

