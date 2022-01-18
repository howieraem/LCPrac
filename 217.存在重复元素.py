#
# @lc app=leetcode.cn id=217 lang=python3
#
# [217] 存在重复元素
#

# @lc code=start
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))
        '''
        s = set()
        for num in nums:
            if num in s:
                return True
            s.add(num)
        return False
        '''

# @lc code=end

