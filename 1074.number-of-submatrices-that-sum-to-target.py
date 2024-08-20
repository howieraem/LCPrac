#
# @lc app=leetcode id=1074 lang=python3
#
# [1074] Number of Submatrices That Sum to Target
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    # T: O(m ^ 2 * n)
    # S: O(m * n)
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])

        prefix_sums = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefix_sums[i][j] = \
                    prefix_sums[i - 1][j] + prefix_sums[i][j - 1] - prefix_sums[i - 1][j - 1] + matrix[i - 1][j - 1]

        submat_sum_cnts = defaultdict(int)
        ans = 0
        for i in range(1, m + 1):
            for j in range(i, m + 1):
                for k in range(1, n + 1):
                    submat_sum = prefix_sums[j][k] - prefix_sums[i - 1][k]
                    if submat_sum == target:
                        ans += 1
                    
                    diff = submat_sum - target
                    diff_cnt = submat_sum_cnts.get(diff, None)
                    if diff_cnt is not None:
                        ans += diff_cnt
                    
                    submat_sum_cnts[submat_sum] += 1
                
                submat_sum_cnts.clear()  # IMPORTANT

        return ans

# @lc code=end

