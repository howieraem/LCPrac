#
# @lc app=leetcode.cn id=137 lang=python3
#
# [137] 只出现一次的数字 II
#
from typing import List

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        """Solution with bit manipulations. One can draw a state machine to assist:
        each of the state represents the count of a number. Binary operation quick
        formuli:
            - x^1 = ~x
            - x^0 = x
            - x&0 = 0
            - x&1 = x
        """
        seen_once = seen_twice = 0
        
        for num in nums:
            # first appearance: 
            # add num to `seen_once`.
            # don't add to `seen_twice` because of presence in seen_once.
            
            # second appearance: 
            # remove num from `seen_once`.
            # add num to `seen_twice`.
            
            # third appearance: 
            # Don't add to `seen_once` because of presence in `seen_twice`.
            # Remove num from `seen_twice`.
            # If a num is seen 3 times, both `seen_once` and `seen_twice` would be 0.
            seen_once = ~seen_twice & (seen_once ^ num)
            seen_twice = ~seen_once & (seen_twice ^ num)

        return seen_once

# @lc code=end
# print(Solution().singleNumber([0,0,0,2]))
