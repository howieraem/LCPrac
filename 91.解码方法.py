#
# @lc app=leetcode.cn id=91 lang=python3
#
# [91] 解码方法
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        # Fibonacci sequence (start from n=2)?
        # '1' -> 1
        # '12' -> 2: {'1 2', '12'}
        # '122' -> 3: {'1 2 2', '1 22', '12 2'}
        # '1221' -> 5: {'1 2 2 1', '12 2 1', '1 22 1', '1 2 21', '12 21'}
        # '12211' -> 8: {'1 2 2 1 1', '1 2 2 11', '12 2 1 1', '12 2 11', '1 22 1 1', '1 22 11', '1 2 21 1', '12 21 1'}

        # '4' -> 1
        # '42' -> 1: {'4 2'}
        # '427' -> 1: {'4 2 7'}

        # '1' -> 1
        # '13' -> 2: {'13', '1 3'}
        # '132' -> 2: {'13 2', '1 3 2'}
        # '1322' -> 4: {'13 2 2', '13 22', '1 3 2 2', '1 3 22'}
        # '13227' -> 4: {'13 2 2 7', '13 22 7', '1 3 2 2 7', '1 3 22 7'}
        # '132271' -> 4: {'13 2 2 7 1', '13 22 7 1', '1 3 2 2 7 1', '1 3 22 7 1'}
        # '1322712' -> 8

        # '0' -> 0
        # '01' -> 0

        # '1' -> 1
        # '11' -> 2: {'1 1', '11'}
        # '110' -> 1: {'1 10'}
        # '1101' -> 1: {'1 10 1'}
        # '11011' -> 2: {'1 10 1 1', '1 10 11'}
        # '110110' -> 1: {'1 10 1 10'}
        # '1101100' -> 0

        # '2' -> 1
        # '20' -> 1
        # '200'
        if not s:
            return 0
        if s[0] == '0':
            return 0
        dp = [1, 1, 0]
        prev = s[0]
        for c in s[1:]:
            if c != '0':
                dp[2] += dp[1]
            if '10' <= prev+c <= '26':
                dp[2] += dp[0]
            
            # Discard an old result and leave a space for new result in next iteration.
            # One can do `dp.pop(0)`` and then `dp.append(0)` too.
            dp[0:2] = dp[1:]
            dp[2] = 0
            prev = c
        return dp[1]

# @lc code=end
s = Solution()
print(s.numDecodings('17'))
