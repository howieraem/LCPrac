#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#
from collections import defaultdict

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        required_chars = defaultdict(int)
        for c in p:
            required_chars[c] += 1
        window = defaultdict(int)

        l = r = valid_cnt = 0
        res = []
        while r < len(s):
            c = s[r]
            r += 1
            if c in required_chars:
                window[c] += 1
                if window[c] == required_chars[c]:
                    valid_cnt += 1
            
            while r - l >= len(p):
                if valid_cnt == len(required_chars):
                    res.append(l)
                d = s[l]
                l += 1
                if d in required_chars:
                    if window[d] == required_chars[d]:
                        valid_cnt -= 1
                    window[d] -= 1
        return res
        
# @lc code=end

