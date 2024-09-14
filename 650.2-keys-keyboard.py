#
# @lc app=leetcode id=650 lang=python3
#
# [650] 2 Keys Keyboard
#

# @lc code=start
class Solution:
    # T: O(n) worst case, if n is a prime number
    # S: O(1)
    def minSteps(self, n: int) -> int:
        ans = 0

        # Idea: use "Copy All" wisely. 
        # Each factor corresponds to a sequence where 
        # "Paste" is repeated after a "Copy All" operation.
        factor = 2
        while n > 1:
            while n % factor == 0:
                ans += factor
                n //= factor
            factor += 1

        return ans

# @lc code=end

