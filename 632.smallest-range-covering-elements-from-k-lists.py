#
# @lc app=leetcode id=632 lang=python3
#
# [632] Smallest Range Covering Elements from K Lists
#
import heapq
from typing import List

# @lc code=start
class Solution:
    # T: O(m + n * log(m)), m := no. of rows, n := no. of cols
    # S: O(m)
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        min_heap = []  # (value, row, col)
        
        cur_max = float('-inf')
        # The heap always contains only one element from each row
        for i, lst in enumerate(nums):
            heapq.heappush(min_heap, (lst[0], i, 0))
            cur_max = max(cur_max, lst[0])

        res = [-1e9, 1e9]
        while len(min_heap) > 0:
            cur_min, i, j = heapq.heappop(min_heap)
            if cur_max - cur_min < res[1] - res[0]:
                res = [cur_min, cur_max]
            
            if j == len(nums[i]) - 1:
                # reaches the max of a row
                return res

            j += 1
            x = nums[i][j]
            cur_max = max(cur_max, x)
            heapq.heappush(min_heap, (x, i, j))

        return res

        
# @lc code=end

