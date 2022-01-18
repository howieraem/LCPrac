#
# @lc app=leetcode.cn id=338 lang=python3
#
# [338] 比特位计数
#

# @lc code=start
class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0]*(num+1)
        for i in range(num+1):
            if i & 1:   # odd number, same as `if i % 2:`
                # examples: 0 = 0b0, 1 = 0b1, 2 = 0b10, 3 = 0b11
                res[i] = res[i-1] + 1
            else:       # even number
                # examples: 2 = 0b10, 4 = 0b100, 8 = 0b1000
                res[i] = res[i // 2]
        return res

        
# @lc code=end

