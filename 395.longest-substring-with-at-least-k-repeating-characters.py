#
# @lc app=leetcode id=395 lang=python3
#
# [395] Longest Substring with At Least K Repeating Characters
#

# @lc code=start
class Solution:
    # T: O(len(s) * alpha_size)
    # S: O(alpha_size)
    def longestSubstring(self, s: str, k: int) -> int:
        N = len(s)
        # convert to char indexes
        OFFSET = ord('a')
        s = [ord(c) - OFFSET for c in s]
        
        ans = 0
        for n_ch_types in range(1, 27):  # substring could contain 1-26 types of char
            freq = [0] * 26
            
            l = r = 0
            n_ch_types_in_window = 0
            n_ch_types_no_less_than_k = 0

            while r < N:
                if n_ch_types_in_window <= n_ch_types:
                    if freq[s[r]] == 0:
                        # new type of char in current window (not in prev window)
                        n_ch_types_in_window += 1
                    freq[s[r]] += 1
                    if freq[s[r]] == k:
                        n_ch_types_no_less_than_k += 1
                    
                    r += 1  # right bound shifts
                else:
                    if freq[s[l]] == k:
                        n_ch_types_no_less_than_k -= 1
                    freq[s[l]] -= 1
                    if freq[s[l]] == 0:
                        n_ch_types_in_window -= 1

                    l += 1  # left bound shifts
                
                if n_ch_types == n_ch_types_in_window == n_ch_types_no_less_than_k:
                    # Only in this condition, the window/substring is eligible
                    ans = max(ans, r - l)

        return ans

# @lc code=end

