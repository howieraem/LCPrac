#
# @lc app=leetcode.cn id=567 lang=python3
#
# [567] 字符串的排列
#
from collections import defaultdict

# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        required_chars = defaultdict(int)
        for c in s1:
            required_chars[c] += 1
        window = defaultdict(int)

        l = r = valid_cnt = 0
        while r < len(s2):
            c = s2[r]
            r += 1
            if c in required_chars:
                window[c] += 1
                if window[c] == required_chars[c]:
                    valid_cnt += 1
            
            while r - l >= len(s1):
                if valid_cnt == len(required_chars):
                    return True
                d = s2[l]
                l += 1
                if d in required_chars:
                    if window[d] == required_chars[d]:
                        valid_cnt -= 1
                    window[d] -= 1
        return False
        

# @lc code=end

