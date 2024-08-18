from typing import List

class Solution:
    # T: O(n)
    # S: O(1) after state compression
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        # N = len(energyDrinkA)
        # dp = [[0, 0, 0] for _ in range(N)]
        dp_a = dp_b = dp_switch = 0

        for i, (a, b) in enumerate(zip(energyDrinkA, energyDrinkB)):
            if i == 0:
                # dp[i][0] = a
                # dp[i][2] = b
                dp_a = a
                dp_b = b
            else:
                # dp[i][0] = max(dp[i - 1][0] + a, dp[i - 1][1] + a)
                # dp[i][2] = max(dp[i - 1][2] + b, dp[i - 1][1] + b)
                # dp[i][1] = max(dp[i - 1][0], dp[i - 1][2])
                dp_a_1 = dp_a
                dp_b_1 = dp_b
                dp_a = max(dp_a_1 + a, dp_switch + a)
                dp_b = max(dp_b_1 + b, dp_switch + b)
                dp_switch = max(dp_a_1, dp_b_1)

        # return max(dp[N - 1])
        return max(dp_a, dp_b)
