#
# @lc app=leetcode id=568 lang=python3
#
# [568] Maximum Vacation Days
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n_weeks * n_cities ^ 2)
    # S: O(n_weeks * n_cities)
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        n_cities = len(flights)
        n_weeks = len(days[0])

        memo = [[0] * n_weeks for _ in range(n_cities)]

        def dfs(cur_city, cur_week):
            if cur_week == n_weeks:
                return 0
            
            if memo[cur_city][cur_week] != 0:
                return memo[cur_city][cur_week]
            
            ans = 0

            for i in range(n_cities):
                # Stay in `cur_city` or another reachable city for `cur_week`.
                # `flights` is actually the adjacency matrix of a graph.
                if flights[cur_city][i] != 0 or i == cur_city:
                    ans = max(ans, days[i][cur_week] + dfs(i, cur_week + 1))

            memo[cur_city][cur_week] = ans
            return ans
        
        return dfs(0, 0)

# @lc code=end

