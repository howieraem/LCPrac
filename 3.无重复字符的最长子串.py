#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        基本思想：从左到右每个字符枚举，找该字符右边最长的不含它本身的字符串的长度

            Example: "abcabcbb"
                i=0, char=a -> (abc)abcbb
                i=1, char=b -> a(bca)bcbb
                i=2, char=c -> ab(cab)cbb
                ...

            时间复杂度：O(n)
        """
        # 哈希集合，记录在指针位置的右边每个字符是否出现过
        occ = set()
        n = len(s)
        # 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        j, ans = -1, 0
        for i in range(n):
            if i != 0:
                # 左指针向右移动一格，移除一个字符
                occ.remove(s[i - 1])
            while j < n - 1 and s[j+1] not in occ:
                # 不断地移动右指针
                j += 1
                occ.add(s[j])
            # 第 i 到 rk 个字符是一个极长的无重复字符子串
            # update maximum with the current substring length
            ans = max(ans, j - i + 1)
        # print(occ)
        return ans

    """
    There is no need to record all substrings.

    Original solution:

    def lengthOfLongestSubstring(self, s: str) -> int:
        substrings = []
        substring = ''
        for c in s:
            if not substring:
                substring = c
            elif c not in substring:
                substring += c
            else:
                if substring not in substrings:
                    substrings.append(substring)
                substring = c
        substrings.append(substring)
        if len(substrings) > 1:
            for i in range(len(substrings)-1):
                str1, str2 = substrings[i:i+2]
                for j, c in enumerate(str1):
                    if c in str2 and j != len(str1) - 1:
                        slice1 = str1[j+1:]
                        new_substring = slice1+str2
                        ncs = set()
                        for k, nc in enumerate(new_substring):
                            if nc not in ncs:
                                ncs.add(nc)
                            else:
                                new_substring = new_substring[:k]
                                break
                        substrings.append(new_substring)
        print(substrings)
        return max(len(x) for x in substrings)
    """

# @lc code=end
# s = Solution()
# print(s.lengthOfLongestSubstring('bpoiexpqhmebhhu'))
