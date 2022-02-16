#
# @lc app=leetcode id=299 lang=python3
#
# [299] Bulls and Cows
#

# @lc code=start
class Solution:
    # T: O(n), n := len(secret)
    # S: O(s), s := alphabet size
    def getHint(self, secret: str, guess: str) -> str:
        cnt = [0] * 10
        a = b = 0
        for s, g in zip(secret, guess):
            if s == g:
                a += 1
            else:
                s, g = int(s), int(g)

                # If the current digit in secret has appeared in guess,
                # or the current digit in guess has appeared in secret
                b += cnt[s] < 0 
                b += cnt[g] > 0
    
                cnt[s] += 1
                cnt[g] -= 1

        return f"{a}A{b}B"
        
# @lc code=end

