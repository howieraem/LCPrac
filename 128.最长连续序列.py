#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#

# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        ans = 0
        for num in nums:
            if num-1 not in nums:
                curr = num
                count = 1
                while curr+1 in nums:
                    curr += 1
                    count += 1
                ans = max(count, ans)
        return ans

# @lc code=end

