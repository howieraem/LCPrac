#
# @lc app=leetcode id=837 lang=python3
#
# [837] New 21 Game
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k + maxPts:  # trivial cases
            return 1.
        
        # When the game ends, the sum of points is between k and k - 1 + maxPts.
        # The probability of getting one specific value from the range [1, maxPts] is 1 / maxPts.
        # The probability of getting k points is:
        #   p(k) = (p(k - 1) + p(k - 2) + ... + p(k - maxPts)) / maxPts
        # Let numerator_sum = p(k - 1) + p(k - 2) + ... + p(k - maxPts).
        # Let dp[i] represent p(i).
        dp = [0.] * (n + 1)
        dp[0] = 1.
        numerator_sum = 1.
        ans = 0.

        # Sliding window with width = maxPts
        for i in range(1, n + 1):
            dp[i] = numerator_sum / maxPts
            if i < k:
                numerator_sum += dp[i]
            else:  
                # Cannot draw more cards.
                # p(x <= n) = p(n) + p(n - 1) + ... + p(k), k <= n
                ans += dp[i]
            if i >= maxPts:
                # Impossible to get i points by drawing only once.
                # Need to subtract the probability of a previous drawing.
                numerator_sum -= dp[i - maxPts]

        return ans

# @lc code=end

