#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 多数元素
#
from typing import List

# @lc code=start
class Solution:
    '''
    def majorityElement(self, nums: List[int]) -> int:
        # Hash table
        d = dict()
        half = len(nums) >> 1
        for num in nums:
            if num not in d:
                d[num] = 1
            else:
                d[num] += 1
            if d[num] > half:
                return num
        return None   # according to input assumptions, this shouldn't happen
    '''

    def majorityElement(self, nums: List[int]) -> int:
        # Moore voting, much better space complexity than hash table
        count, candidate = 0, None
        for num in nums:
            if not count:
                candidate = num
            if num == candidate:
                count += 1
            else:
                count -= 1
        return candidate

# @lc code=end

