#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(s), s := 128
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen_idxs = [-1] * 128  # there are 128 ASCII char types
        ans = 0

        l = r = 0
        while r < len(s):
            c = ord(s[r])
            if last_seen_idxs[c] != -1:
                # Now the char at the right boundary of the window should equal 
                # the left boundary char, so need to shift the left boundary.
                # Both left and right pointers can be shifted to the right only, so
                # update `l` only if the last seen index of the char is larger.
                l = max(l, last_seen_idxs[c] + 1)
            last_seen_idxs[c] = r
            
            ans = max(ans, r - l + 1)
            r += 1

        return ans

# @lc code=end

