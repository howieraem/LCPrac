#
# @lc app=leetcode.cn id=205 lang=python3
#
# [205] 同构字符串
#

# @lc code=start
class Solution:
    '''
    def isIsomorphic(self, s: str, t: str) -> bool:
        d = {}
        for i in range(len(s)):     # given len(s) = len(t)
            if s[i] not in d:
                if t[i] in d.values():
                    return False
                d[s[i]] = t[i]
            elif d[s[i]] != t[i]:
                return False
        return True
    '''

    # hash map
    # T: O(n)
    # S: O(alpha_size)
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        # 128 is the number of ASCII characters
        map_s = [-1] * 128  # k: char, v: last appear idx
        map_t = [-1] * 128  # k: char, v: last appear idx

        for i, (cs, ct) in enumerate(zip(s, t)):
            cidx_s = ord(cs)
            cidx_t = ord(ct)
            if map_s[cidx_s] != map_t[cidx_t]:
                return False

            map_s[cidx_s] = i
            map_t[cidx_t] = i
        
        return True

        
# @lc code=end

