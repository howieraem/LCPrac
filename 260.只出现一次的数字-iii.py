#
# @lc app=leetcode.cn id=260 lang=python3
#
# [260] 只出现一次的数字 III
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        # For numbers appearing twice, their XOR is 0, so
        # s will become the XOR between the two targets.
        s = 0
        for num in nums:
            s ^= num

        # Find the right most 1 of s in binary.
        # At this digit, one target is 1 and another is 0.
        s &= -s

        # Split the numbers into two groups w.r.t. the right most 1 of s,
        # and the two targets equal to the XOR of the groups respectively.
        res = [0, 0]
        for num in nums:
            if s & num:
                res[0] ^= num
            else:
                res[1] ^= num
        return res


# @lc code=end

