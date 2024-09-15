from typing import List

class Solution:
    # T: O(n)
    # S: O(1)
    def maxScore(self, a: List[int], b: List[int]) -> int:
        n = len(b)

        # dpi[i] means max score achievable for the first i terms
        # As dpi[i] only depends on dpi[i - 1], compress states
        dp0 = a[0] * b[0]  # base case dp0[0]
        dp1 = float('-inf')
        dp2 = float('-inf')
        dp3 = float('-inf')

        for i in range(1, n):
            # dp0[i] = max(dp0[i - 1], a[0] * b[i])
            # dp1[i] = max(dp1[i - 1], dp0[i - 1] + a[1] * b[i])
            # dp2[i] = max(dp2[i - 1], dp1[i - 1] + a[2] * b[i])
            # dp3[i] = max(dp3[i - 1], dp2[i - 1] + a[3] * b[i])
            last_dp0 = dp0
            dp0 = max(dp0, a[0] * b[i])
            last_dp1 = dp1
            dp1 = max(dp1, last_dp0 + a[1] * b[i])
            last_dp2 = dp2
            dp2 = max(dp2, last_dp1 + a[2] * b[i])
            dp3 = max(dp3, last_dp2 + a[3] * b[i])
        
        return dp3
