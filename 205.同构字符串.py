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
    def isIsomorphic(self, s: str, t: str) -> bool:
        map_s = [0] * 128    # 128 is the number of ASCII characters
        map_t = [0] * 128
        for i in range(len(s)):     # given len(s) = len(t)
            cidx_s, cidx_t = ord(s[i]), ord(t[i])
            if map_s[cidx_s] != map_t[cidx_t]:
                return False
            if not map_s[cidx_s]:   
                # Record positions if not appeared before.
                # No need to update anymore.
                map_s[cidx_s] = i + 1
                map_t[cidx_t] = i + 1
        return True

        
# @lc code=end

