#
# @lc app=leetcode id=838 lang=python3
#
# [838] Push Dominoes
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def pushDominoes(self, dominoes: str) -> str:
        N = len(dominoes)
        l = -1
        r = -1
        res = list(dominoes)        

        for i in range(N + 1):
            if i == N or res[i] == 'R':
                if r > l:   
                    # R...R, turn all to R
                    while r < i:
                        res[r] = 'R'
                        r += 1
                # else: r < l, L...R, do nothing
                r = i
            elif res[i] == 'L':
                if l > r or r == -1:
                    # L...L, turn all to L
                    while l < i - 1:
                        l += 1
                        res[l] = 'L'
                else:  # R...L, turn until lo = hi
                    l = i
                    lo = r + 1
                    hi = l - 1
                    while lo < hi:
                        res[lo] = 'R'
                        res[hi] = 'L'
                        lo += 1
                        hi -= 1
        
        return ''.join(res)

        
# @lc code=end

