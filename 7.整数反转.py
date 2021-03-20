#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    """
    approach 1: direct operations on the number and its digits
    approach 2: convert to string, reverse and convert back (can be slower)

    Notes: MAX_INT and MIN_INT are not problematic in python,
        but in C/C++ and Java.
    """
    def reverse(self, x: int) -> int:
        y, ans = abs(x), 0
        # 数值范围为 [−2^31,  2^31−1]
        boundry = (1<<31) - (x > 0)     # abs val here as well
        while y:
            ans = ans*10 + y%10
            if ans > boundry:   # overflow early stop
                return 0
            y //= 10
        return ans if x > 0 else -ans

    """
    original solution:

    def reverse(self, x: int) -> int:
        neg = x < 0
        if neg:
            x = abs(x)
        digits = []
        while x:
            x, digit = divmod(x, 10)
            digits.append(digit)
        ans = 0
        n = r = len(digits)
        while r:
            r -= 1
            ans += digits[r]*10**(n-r-1)
        if neg:
            ans = -ans
            if ans < -2**31:
                return 0
            return ans
        return 0 if ans > 2**31-1 else ans
    """

# @lc code=end
s = Solution()
print(s.reverse(-123))
