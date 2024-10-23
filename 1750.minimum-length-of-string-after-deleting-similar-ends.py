#
# @lc app=leetcode id=1750 lang=python3
#
# [1750] Minimum Length of String After Deleting Similar Ends
#

# @lc code=start
class Solution:
    # two pointers
    # T: O(n)
    # S: O(1)
    def minimumLength(self, s: str) -> int:
        l = 0
        r = len(s) - 1

        # IMPORTANT: terminate when l < r because prefix and suffix can't overlap
        while l < r and s[l] == s[r]:
            cur_c = s[l]

            # Remove prefix of same char: shift as left as possible
            while l <= r and s[l] == cur_c:
                l += 1

            # Remove suffix of same char: shift as right as possible
            while l <= r and s[r] == cur_c:
                r -= 1
        
        return r - l + 1  # this handles empty input as well

# @lc code=end

