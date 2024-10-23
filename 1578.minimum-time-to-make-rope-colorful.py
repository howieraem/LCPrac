#
# @lc app=leetcode id=1578 lang=python3
#
# [1578] Minimum Time to Make Rope Colorful
#
from typing import List

# @lc code=start
class Solution:
    # Greedy / DP
    # T: O(n)
    # S: O(1)
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        N = len(colors)
        if N == 0:
            return 0
        
        ans = 0
        cur_max_cost = neededTime[0]

        for i in range(1, N):
            if colors[i] == colors[i - 1]:
                # Found a group with the same color, 
                # remove ballon with the less cost
                if cur_max_cost > neededTime[i]:
                    ans += neededTime[i]
                else:
                    ans += cur_max_cost
                    cur_max_cost = neededTime[i]
            else:
                # A different color/group
                cur_max_cost = neededTime[i]

        return ans

# @lc code=end

