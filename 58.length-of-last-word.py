#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0

        ans = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ':
                if ans != 0:
                    # already seen a word
                    break

                # haven't reached a word yet
                continue
            ans += 1

        return ans

        
# @lc code=end

