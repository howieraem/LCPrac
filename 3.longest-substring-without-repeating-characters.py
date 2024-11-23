#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(alpha_size), alpha_size := 128
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen_idxs = [-1] * 128  # there are 128 ASCII char types
        ans = 0

        l = 0
        for r in range(len(s)):
            ci = ord(s[r])
            
            if last_seen_idxs[ci] >= l:
                # Now the char at the right boundary of the window should equal 
                # the left boundary char, so need to shift the left boundary.
                l = last_seen_idxs[ci] + 1
            
            last_seen_idxs[ci] = r
            ans = max(ans, r - l + 1)

        return ans

# @lc code=end

