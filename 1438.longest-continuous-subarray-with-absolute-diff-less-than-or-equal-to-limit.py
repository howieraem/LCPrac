#
# @lc app=leetcode id=1438 lang=python3
#
# [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
#
from collections import deque
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        # Use 2 mono-deques
        max_deque = deque()  # queue front is the maximum
        min_deque = deque()  # queue front is the minimum

        i = 0
        ans = 1
        for j, x in enumerate(nums):
            while len(max_deque) and max_deque[-1] < x:
                max_deque.pop()
            while len(min_deque) and min_deque[-1] > x:
                min_deque.pop()
            
            max_deque.append(x)
            min_deque.append(x)

            # sliding window: shift the left boundary
            if max_deque[0] - min_deque[0] > limit:
                if max_deque[0] == nums[i]:
                    max_deque.popleft()
                if min_deque[0] == nums[i]:
                    min_deque.popleft()
                i += 1
        
            ans = max(ans, j - i + 1)
        
        return ans
        
# @lc code=end

