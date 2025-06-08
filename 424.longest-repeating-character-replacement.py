#
# @lc app=leetcode id=424 lang=python3
#
# [424] Longest Repeating Character Replacement
#

# @lc code=start
class Solution:
    # Sliding window + Hash map
    # T: O(n)
    # S: O(alpha_size), alpha_size := 26
    def characterReplacement(self, s: str, k: int) -> int:
        OFFSET = ord('A')
        cnts = [0] * 26
        max_cnt = 0
        ans = 0
        
        l = 0
        for r in range(len(s)):
            c = ord(s[r]) - OFFSET
            cnts[c] += 1
            max_cnt = max(cnts[c], max_cnt)
            
            # Idea: keep the kind of char with the maximum count and 
            # try to replace other kinds of chars. If there are too 
            # many other chars to replace, shift the left boundary 
            # of the window.
            while r - l + 1 > max_cnt + k:
                cnts[ord(s[l]) - OFFSET] -= 1
                l += 1

            # At this point, window width = max_cnt + k, all chars in the window 
            # can be made the same, so update ans
            ans = max(ans, r - l + 1)
        
        return ans

# @lc code=end

