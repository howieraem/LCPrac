#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#

# @lc code=start
class Solution:
    
    def longestPalindrome(self, s: str) -> str:
        """
        动态规划法, O(N^2)

        `dp[i][j]` indicates whether `s[i:j+1]` is a palindrome.
        bottom-top approach, building from small i and j to large.
        
        思想：不重复匹配字符，记录已匹配的位置
        """
        n = len(s)
        dp = [[False] * n for _ in range(n)]    # n*n array
        ans = ""

        for right in range(n):
            for left in range(right+1):
                if s[right] == s[left] and (right - left <= 2 or dp[left + 1][right - 1]):
                    # examples of `right - left <= 2`: "aa", "a", etc.
                    dp[left][right] = True

                    # update the longest
                    if right-left+1 > len(ans):
                        ans = s[left:right+1]
        return ans

    """
    Original Solution, O(N^3):
    
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        if l < 2:
            return s
        curr_substring = ''
        for i in range(l):  # O(N)
            c1 = s[i]
            j = len(s)-1
            while i <= j:   # O(N)
                if s[j] == c1:
                    substring = s[i:j+1]
                    lsub = len(substring)

                    # note: `[::-1]` is not directly available in other languages, need another while loop.
                    if substring == substring[::-1]:   # O(N)
                        if lsub > l - 2:   # heuristic?? as only need to return one longest
                            return substring
                        if lsub > len(curr_substring):
                            curr_substring = substring
                j -= 1
        return curr_substring
    """
    
    def longestPalindrome(self, s: str) -> str:
        """Manacher Algorithm with time complexity O(N).
        The approach is based on center expansion and KMP."""
        # 特判
        size = len(s)
        if size < 2:
            return s

        # 得到预处理字符串
        t = "#"
        for i in range(size):
            t += s[i]
            t += "#"
        len_t = len(t)  # 2*size+1

        # 记录扫描过的回文子串的信息
        p = [0]*len_t

        # 双指针，须同时更新
        max_right = 0
        center = 0

        # 当前遍历的中心最大扩散步数，其值等于原始字符串的最长回文子串的长度
        max_len = 1
        # 原始字符串的最长回文子串的起始位置，与 max_len 必须同时更新
        start = 1

        for i in range(len_t):
            if i < max_right:
                mirror = 2 * center - i
                # 对称回文范围取值不能超过右指针
                p[i] = min(max_right - i, p[mirror])

            # 下一次尝试扩散的左右起点，能扩散的步数直接加到`p[i]`中
            left = i - (1 + p[i])
            right = i + (1 + p[i])

            # `left >= 0 and right < len_r`保证不越界
            # `t[left] == t[right]`表示可以扩散1次
            while left >= 0 and right < len_t and t[left] == t[right]:
                p[i] += 1
                left -= 1
                right += 1

            # 根据`max_right`的定义，它是遍历过的`i`的`i + p[i]`的最大者
            # 如果`max_right`的值越大，进入上面`i < max_right`的判断的可能性就越大，这样就可以重复利用之前判断过的回文信息了
            if i + p[i] > max_right:
                # `max_right`和`center`需要同时更新
                max_right = i + p[i]
                center = i

            if p[i] > max_len:
                # 记录最长回文子串的长度和相应它在原始字符串中的起点
                max_len = p[i]
                start = (i - max_len) // 2
        return s[start:start+max_len]


# @lc code=end
# s = Solution()
# print(s.longestPalindrome('abaaba'))
