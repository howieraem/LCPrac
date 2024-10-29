#
# @lc app=leetcode id=373 lang=python3
#
# [373] Find K Pairs with Smallest Sums
#
import heapq
from typing import *

# @lc code=start
class Solution:
    # Heap + two pointers
    # T: O(k * log(k))
    # S: O(k)
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        m = len(nums1)
        n = len(nums2)
        if m == 0 or n == 0:
            return []

        vis = set()   # avoid possibly duplicate index pairs 
        min_heap = []
        res = []

        heapq.heappush(min_heap, (nums1[0] + nums2[0], (0, 0)))
        vis.add((0, 0))

        while len(res) < k and min_heap:
            _, (i, j) = heapq.heappop(min_heap)
            res.append((nums1[i], nums2[j]))

            ni = i + 1
            pair = (ni, j)

            if ni < m and pair not in vis:
                heapq.heappush(min_heap, (nums1[ni] + nums2[j], pair))
                vis.add(pair)

            nj = j + 1
            pair = (i, nj)

            if nj < len(nums2) and pair not in vis:
                heapq.heappush(min_heap, (nums1[i] + nums2[nj], pair))
                vis.add(pair)

        return res

# @lc code=end

