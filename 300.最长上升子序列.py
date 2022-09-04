#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长上升子序列
#
from typing import List

# @lc code=start
class Solution:
    """Note: the subsequence requires correct ordering but not contiguity of elements."""
    '''
    def lengthOfLIS(self, nums: List[int]) -> int:
        """Dynamic programming approach. Time complexity O(N^2)."""
        n = len(nums)
        if n < 2:
            return n
        dp = [1]*n  # `dp[i]` means length of LIS for `nums[:i]`.
        ans = 0
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]: # 若要求非严格递增，`<`改为`<=`
                    dp[i] = max(dp[i], dp[j] + 1)
            ans = max(dp[i], ans)
        return ans
    '''

    def lengthOfLIS(self, nums: List[int]) -> int:
        """Sorted DP array with binary search. Time complexity O(Nlog(N))."""
        n = len(nums)
        if n < 2:
            return n
        tails = [nums[0]]
        for i in range(1, n):
            if nums[i] > tails[-1]:     # 若要求非严格递增，`>`改为`>=`
                # tails is always sorted, so binary search is applicable.
                tails.append(nums[i])   
                continue
            left = 0
            right = len(tails) - 1
            while left <= right:
                mid = (left + right) >> 1
                if tails[mid] >= nums[i]:
                    right = mid - 1
                else:
                    left = mid + 1
            tails[left] = nums[i]
        return len(tails)
        
# @lc code=end
