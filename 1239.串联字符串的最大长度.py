#
# @lc app=leetcode.cn id=1239 lang=python3
#
# [1239] 串联字符串的最大长度
#

# @lc code=start
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        self.masks = []
        for s in arr:
            mask = 0
            for c in s:
                i = ord(c) - ord('a')
                if ((mask >> i) & 1):
                    # a character exists more than once in the string
                    mask = 0
                    break
                mask |= 1 << i
                
            # only use non-empty strings without duplicate characters
            if mask > 0:
                self.masks.append(mask)

        self.n = len(self.masks)
        self.ans = 0

        # starts with empty string "" (mask 0)
        self.backtrack(0, 0)
        return self.ans

    def backtrack(self, idx, mask):
        if idx == self.n:
            self.ans = max(self.ans, bin(mask).count("1"))
            return

        if not (mask & self.masks[idx]):
            # no characters in common
            self.backtrack(idx + 1, mask | self.masks[idx])
        self.backtrack(idx + 1, mask)

# @lc code=end
