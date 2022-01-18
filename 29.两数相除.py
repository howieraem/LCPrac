#
# @lc app=leetcode.cn id=29 lang=python3
#
# [29] 两数相除
#

# @lc code=start
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        """Solution with bit shifting. 
        
        Notes: Java allows negative number bit shifting but
            C/C++ does not.
        """
        neg = (dividend < 0) ^ (divisor < 0)
        if dividend < 0:
            dividend = -dividend    # avoid using abs() and thus overflow
        if divisor < 0:
             divisor = -divisor     # avoid using abs() and thus overflow
        if divisor == 1:
            ret = dividend
        elif not divisor:
            raise ValueError
        else:
            count = 0
            # 把除数不断左移，直到它大于被除数
            while dividend >= divisor:
                count += 1
                divisor <<= 1
            ret = 0
            while count > 0:
                count -= 1
                divisor >>= 1
                if divisor <= dividend:
                    ret += 1 << count # 这里的移位运算是把二进制（第count+1位上的1）转换为十进制
                    dividend -= divisor
        if neg: 
            ret = -ret
        return ret if -(1<<31) <= ret <= (1<<31)-1 else (1<<31)-1

    """
    original solution, based on definition of division, but too slow
    when dividend is much greater than divisor:

    def divide(self, dividend: int, divisor: int) -> int:
        neg = (dividend < 0) ^ (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        if divisor == 1:
            ret = dividend
        else:
            ret = 0
            while dividend - divisor >= 0:
                dividend -= divisor
                ret += 1
        if neg:
            ret = -ret
        if ret > 2**31 - 1 or ret < -2**31:
            return 2**31 - 1
        return ret
    """

# @lc code=end
s = Solution()
print(s.divide(2147483647, 2))
