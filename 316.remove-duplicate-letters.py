#
# @lc app=leetcode id=316 lang=python3
#
# [316] Remove Duplicate Letters
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n + alpha_size)
    def removeDuplicateLetters(self, s: str) -> str:
        OFFSET = ord('a')
        freq = [0] * 26

        for c in s:
            cidx = ord(c) - OFFSET
            freq[cidx] += 1

        vis = [False] * 26  # ensure uniqueness
        res = []
        for c in s:
            cidx = ord(c) - OFFSET
            if not vis[cidx]:
                # Mono-stack: chars in stack are sorted ASC, ensuring result is lexicographically smallest
                # IMPORTANT: if no last type of char remains, don't pop
                while len(res) > 0 and res[-1] > c and freq[ord(res[-1]) - OFFSET] > 0:  
                    vis[ord(res[-1]) - OFFSET] = False
                    res.pop()
                
                res.append(c)
                vis[cidx] = True
            freq[cidx] -= 1

        return ''.join(res)

# @lc code=end

