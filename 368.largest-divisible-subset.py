#
# @lc app=leetcode id=368 lang=python3
#
# [368] Largest Divisible Subset
#
from typing import List

# @lc code=start
class Solution:
    # 2D DP + graph path
    # T: O(n ^ 2)
    # S: O(n)
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        # we need subset, not subsequence, so it's easier to sort beforehand
        nums.sort()
        
        n = len(nums)

        # dp_sz[i] means the size of the largest subset with all 
        # pairs meeting the modulo requirement for nums[:i+1]
        dp_sz = [0] * n

        # for backward constructing result
        max_sz = 0
        pre_idxs = [0] * n
        last_idx = -1

        for i in range(n):
            dp_sz[i] = 1   # base case
            pre_idxs[i] = -1

            for j in range(i - 1, -1, -1):
                if nums[i] % nums[j] == 0 and dp_sz[i] < dp_sz[j] + 1:
                    dp_sz[i] = dp_sz[j] + 1
                    pre_idxs[i] = j  # record the largest subset path

            if max_sz < dp_sz[i]:
                max_sz = dp_sz[i]
                last_idx = i

        res = [0] * max_sz
        while max_sz > 0:  # while last_idx != -1
            # Collect result from back to front because we start from last index 
            # (if order matters)
            res[max_sz - 1] = nums[last_idx]  
            last_idx = pre_idxs[last_idx]
            max_sz -= 1
        return res


# @lc code=end

