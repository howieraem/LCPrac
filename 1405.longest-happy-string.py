#
# @lc app=leetcode id=1405 lang=python3
#
# [1405] Longest Happy String
#

# @lc code=start
class Solution:
    # Greedy: always append the letter with the highest remaining count 
    #         if the letter's current contiguous count is less than 2
    # T: O(a + b + c)
    # S: O(a + b + c)
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        n = a + b + c
        res = [''] * n
        cur_a = cur_b = cur_c = 0
        for i in range(n):
            if (a >= b and a >= c and cur_a != 2) or (a > 0 and a >= c and cur_b == 2) or (a > 0 and a >= b and cur_c == 2):
                res[i] = 'a'
                a -= 1
                cur_a += 1
                cur_b = cur_c = 0
            elif (b >= a and b >= c and cur_b != 2) or (b > 0 and b >= c and cur_a == 2) or (b > 0 and b >= a and cur_c == 2):
                res[i] = 'b'
                b -= 1
                cur_b += 1
                cur_a = cur_c = 0
            elif (c >= a and c >= b and cur_c != 2) or (c > 0 and c >= b and cur_a == 2) or (c > 0 and c >= a and cur_b == 2):
                res[i] = 'c'
                c -= 1
                cur_c += 1
                cur_a = cur_b = 0
        return ''.join(res)

        
# @lc code=end

