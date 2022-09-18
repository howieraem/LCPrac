#
# @lc app=leetcode id=424 lang=python3
#
# [424] Longest Repeating Character Replacement
#

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(s), s := 26
    def characterReplacement(self, s: str, k: int) -> int:
        cnts = [0] * 26
        max_cnt = 0
        ans = 0
        
        l = 0
        for r in range(len(s)):
            c = ord(s[r]) - ord('A')
            cnts[c] += 1
            max_cnt = max(cnts[c], max_cnt)
            
            # Idea: keep the kind of char with the maximum count and 
            # try to replace other kinds of chars. If there are too 
            # many other chars to replace, shift the left boundary 
            # of the window.
            while r - l + 1 - max_cnt > k:
                cnts[ord(s[l]) - ord('A')] -= 1
                l += 1
        
            ans = max(ans, r - l + 1)
        
        return ans

# @lc code=end

