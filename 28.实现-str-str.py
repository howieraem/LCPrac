#
# @lc app=leetcode.cn id=28 lang=python3
#
# [28] 实现 strStr()
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """Implements KMP algorithm."""
        if not needle:
            return 0
        '''Calculate failure function (array)'''
        n, m = len(haystack), len(needle)
        f = [0]*m
        i, j = 1, 0
        while i < m:
            if needle[i] == needle[j]:
                f[i] = j+1
                i += 1
                j += 1
            elif j > 0:
                j = f[j-1]
            else:
                # j[i] = 0
                i += 1
        # print(f)

        '''Begin KMP matching'''
        i = j = 0
        while i < n:
            if haystack[i] == needle[j]:
                if j == m - 1:
                    return i-j  # a match
                else:
                    i += 1
                    j += 1
            else:
                if j > 0:
                    j = f[j-1]
                else:
                    i += 1
        return -1

    def strStr(self, haystack: str, needle: str) -> int:
        """Sliding-window approach."""
        n, m = len(haystack), len(needle)
        for start in range(n - m + 1):
            if haystack[start:start+m] == needle:
                return start
        return -1

# @lc code=end
# print(Solution().strStr('hello', 'll'))
