#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    # sliding window
    # T: O(len(s) + len(p))
    # S: O(alpha_size)
    def findAnagrams(self, s: str, p: str) -> List[int]:
        required_chars = defaultdict(int)
        for c in p:
            required_chars[c] += 1
        window = defaultdict(int)

        l = r = valid_cnt = 0
        res = []
        while r < len(s):
            # Expand window to the right
            c_r = s[r]
            r += 1
            if c_r in required_chars:
                window[c_r] += 1
                if window[c_r] == required_chars[c_r]:
                    valid_cnt += 1
            
            while r - l >= len(p):
                if valid_cnt == len(required_chars):
                    res.append(l)

                # Try shrinking window by moving the left pointer,
                # then update the counts.
                c_l = s[l]
                if c_l in required_chars:
                    if window[c_l] == required_chars[c_l]:
                        valid_cnt -= 1
                    window[c_l] -= 1
                l += 1
        return res
        
# @lc code=end

