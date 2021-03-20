#
# @lc app=leetcode.cn id=581 lang=python3
#
# [581] 最短无序连续子数组
#

# @lc code=start
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        """O(Nlog(N)) approach."""
        sorted_nums, n = sorted(nums), len(nums)
        begin, end = n-1, 0
        for i in range(n):
            if sorted_nums[i] != nums[i]:
                begin = min(begin, i)
                end = max(end, i)
        return end - begin + 1 if end > begin else 0

    def findUnsortedSubarray(self, nums: List[int]) -> int:
        """O(N) approach."""
        n = len(nums)
        min_val, max_val = nums[-1], nums[0]
        begin, end = 0, -1
        for i in range(n):
            # 从左到右维持最大值，寻找右边界end
            if nums[i] < max_val:
                end = i
            else:
                max_val = nums[i]

            # 从右到左维持最小值，寻找左边界begin
            if nums[n-i-1] > min_val:
                begin = n-i-1
            else:
                min_val = nums[n-i-1]
        return end-begin+1
        
# @lc code=end

