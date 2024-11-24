#
# @lc app=leetcode id=1935 lang=python3
#
# [1935] Maximum Number of Words You Can Type
#

# @lc code=start
OFFSET = ord('a')

class Solution:
    # Hash set
    # T: O(n + alpha_size)
    # S: O(alpha_size)
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        is_broken = [False] * 26
        for c in brokenLetters:
            is_broken[ord(c) - OFFSET] = True

        ans = 0
        for w in text.split():
            can_type = True
            for c in w:
                if is_broken[ord(c) - OFFSET]:
                    can_type = False
                    break
            
            ans += can_type

        return ans

# @lc code=end

