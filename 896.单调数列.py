#
# @lc app=leetcode.cn id=896 lang=python3
#
# [896] 单调数列
#

# @lc code=start
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        inc = dec = True
        for i in range(len(A) - 1):
            if A[i] > A[i + 1]:
                inc = False
            if A[i] < A[i + 1]:
                dec = False
            if not (inc or dec):
                return False
        return True
        
# @lc code=end

