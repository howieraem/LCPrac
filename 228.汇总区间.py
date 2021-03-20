#
# @lc app=leetcode.cn id=228 lang=python3
#
# [228] 汇总区间
#

# @lc code=start
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        n = len(nums)
        i = 0
        for j in range(n):
            if j + 1 < n and nums[j + 1] == nums[j] + 1:
                continue
            if i == j:
                res.append(str(nums[i]))
            else:
                res.append(str(nums[i]) + '->' + str(nums[j]))
            i = j + 1
        return res

# @lc code=end

