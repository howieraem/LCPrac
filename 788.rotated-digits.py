#
# @lc app=leetcode id=788 lang=python3
#
# [788] Rotated Digits
#

# @lc code=start
class Solution:
    """
    After rotation:
        case 0, invalid digits: 3, 4, 7
        case 1, valid and same digits: 0, 1, 8
        case 2, valid and different digits: 2, 5, 6, 9

    Intuitive solution: 
        For each number from 1 to n, check each digit after rotation,
        and increment count if there are 2 or more numbers generated.
        https://leetcode.com/problems/rotated-digits/discuss/130681
        https://leetcode.com/problems/rotated-digits/discuss/116547
        T: O(n * log(n))
        S: O(1)
    """

    # Improve time complexity with auxiliary space
    # T: O(n)
    # S: O(n)
    def rotatedDigits(self, n: int) -> int:
        digit_different_counts = (1, 1, 2, 0, 0, 2, 2, 0, 1, 2)
        dp = [0] * (n + 1)
        ans = 0
        for i in range(n + 1):
            if i < 10:
                dp[i] = digit_different_counts[i]
                ans += dp[i] == 2
            else:
                a = dp[i // 10]
                b = dp[i % 10]
                if a == 1 and b == 1:
                    dp[i] = 1
                elif a >= 1 and b >= 1:
                    # a == 1 and b == 2
                    # a == 2 and b == 1
                    # a == 2 and b == 2
                    dp[i] = 2
                    ans += 1
        return ans

    # Another solution (more mathematical): 
    # https://leetcode.com/problems/rotated-digits/discuss/116530/JavaPython-O(logN)-Time-O(1)-Space/742039
    # T: O(log(n))
    # S: O(log(n))

# @lc code=end

