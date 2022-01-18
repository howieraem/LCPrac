#
# @lc app=leetcode.cn id=263 lang=python3
#
# [263] 丑数
#

# @lc code=start
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:
            return False
        ugly_set = {1, 2, 3, 5}
        
        while True:
            if num in ugly_set:
                return True
            
            if not num % 2:
                num /= 2
            elif not num % 3:
                num /= 3
            elif not num % 5:
                num /= 5
            else:
                return False


# @lc code=end

