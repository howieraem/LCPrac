#
# @lc app=leetcode id=1235 lang=python3
#
# [1235] Maximum Profit in Job Scheduling
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(n)
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(startTime)

        # Sort by start and then end
        jobs = sorted([(startTime[i], endTime[i], profit[i]) for i in range(n)])
        
        dp = dict()

        def memo_dfs(i):
            if i == n:
                return 0
            if i in dp:
                return dp[i]

            # Option 1: take the current job, and find the next available one
            res_incl = jobs[i][2]
            next_i = self.find_next_job(jobs, i)
            if next_i != -1:
                res_incl += memo_dfs(next_i)

            # Option 2: skip the current job
            res_excl = memo_dfs(i + 1)

            res = max(res_incl, res_excl)
            dp[i] = res
            return res

        return memo_dfs(0)

    @staticmethod
    def find_next_job(jobs: List[Tuple], i: int) -> int:
        for j in range(i + 1, len(jobs)):
            if jobs[j][0] >= jobs[i][1]:
                # Next start time greater than current end time,
                # no overlap.
                return j
        return -1

# @lc code=end

