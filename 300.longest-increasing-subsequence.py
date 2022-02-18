#
# @lc app=leetcode id=300 lang=python3
#
# [300] Longest Increasing Subsequence
#
from typing import List

# @lc code=start
class Solution:
    '''
    # Solution 1: DP
    # T: O(n ^ 2)
    # S: O(n)
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)

        # dp[i] means the length of the longest increasing subseq in nums[:i + 1]
        dp = [1] * n
    
        ans = 0
        for i in range(n):
            for j in range(i):
                # i > j
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

            ans = max(ans, dp[i])

        return ans
    '''

    # Solution 2: Greedy + Binary Search
    # T: O(n * log(n))
    # S: O(n)
    # https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = []
        for x in nums:
            if not len(sub) or sub[-1] < x:
                # Extend the length
                sub.append(x)
            else:
                # Find the index of the number in sub that is no less than x,
                # and replace that number with x
                idx = self.lower_bound(sub, x)
                sub[idx] = x
        # Note that `sub` here is not the actual longest subsequence, 
        # but `len(sub)` is the answer
        return len(sub)

    # This version returns the actual longest subsequence
    def lengthOfLIS_F(self, nums: List[int]) -> int:
        sub = []
        sub_idxs = []
        path = [-1] * len(nums)
        for i, x in enumerate(nums):
            if not len(sub) or sub[-1] < x:
                sub.append(x)
                path[i] = -1 if not len(sub_idxs) else sub_idxs[-1]
                sub_idxs.append(i)
            else:
                idx = self.lower_bound(sub, x)
                sub[idx] = x
                path[i] = -1 if idx == 0 else sub_idxs[idx - 1]
                sub_idxs[idx] = i
        
        res = []
        t = sub_idxs[-1]
        while t >= 0:
            res.append(nums[t])
            t = path[t]
        res.reverse()
        return res

    @staticmethod
    def lower_bound(nums: List[int], target: int):
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) >> 1
            if nums[m] >= target:
                r = m - 1
            else:
                l = m + 1
        if l >= len(nums):
            return len(nums) - 1
        return l

# @lc code=end

