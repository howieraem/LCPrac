#
# @lc app=leetcode.cn id=45 lang=python3
#
# [45] 跳跃游戏 II
#

# @lc code=start
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        furthest = 0
        ans = 0

        end = 0     # at index i, can jump to end at the furthest
        for i in range(n - 1):
            furthest = max(furthest, i + nums[i])
            if end == i:
                # only jumps when current i equals last end
                ans += 1
                end = furthest  # update end
            
        return ans

# @lc code=end

