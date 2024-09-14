#
# @lc app=leetcode id=691 lang=python3
#
# [691] Stickers to Spell Word
#
from typing import List

# @lc code=start
class Solution:
    # T: O((n * (t + 26)) * 2 ^ t), n := len(stickers), t := len(target)
    # S: O(2 ^ t) the number of different subset of chars from target
    def minStickers(self, stickers: List[str], target: str) -> int:
        OFFSET = ord('a')
        n = len(stickers)
        sticker_char_cnts = [[0] * 26 for _ in range(n)]
        for i, s in enumerate(stickers):
            for c in s:
                sticker_char_cnts [i][ord(c) - OFFSET] += 1

        memo = dict()
        memo[""] = 0   # IMPORTANT base case
        MAX = float('inf')

        def dfs(t: str) -> int:
            cache = memo.get(t, None)
            if cache is not None:
                return cache
            
            target_char_cnts = [0] * 26
            for c in t:
                target_char_cnts[ord(c) - OFFSET] += 1
            
            ans = MAX
            for i in range(n):
                # IMPORTANT pruning: 
                # If sticker i doesn't contain the 1st target character 
                # but contains the character after it and that character is 
                # unique, the sticker will still be picked in future recursions 
                # when that character become the 1st character.
                if sticker_char_cnts[i][ord(t[0]) - OFFSET] == 0:
                    continue

                # pick sticker i
                nt = []
                for j in range(26):
                    diff = target_char_cnts[j] - sticker_char_cnts[i][j]
                    if diff > 0:
                        # still need extra stickers
                        nt.append(chr(j + OFFSET) * diff)

                # target reduced after picking sticker i; covers base case ""
                sub = dfs(''.join(nt))
                if sub != -1:
                    ans = min(ans, sub + 1)
            
            if ans == MAX:
                ans = -1
            memo[t] = ans
            return ans

        return dfs(target)

        
# @lc code=end

