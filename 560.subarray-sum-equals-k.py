#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    # As nums contains negative numbers, we can't use sliding window.
    # Idea: the sum of a subarray equals the difference 
    # between two prefix sums.
    # T: O(n)
    # S: O(n)
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum_cnts = defaultdict(int)
        prefix_sum_cnts[0] = 1  # IMPORTANT
        p_sum = 0

        ans = 0
        for num in nums:
            p_sum += num
            prefix_sum_cnts[p_sum] += 1

            another_p_sum = p_sum - k
            if another_p_sum in prefix_sum_cnts:
                ans += prefix_sum_cnts[another_p_sum]

        return ans

    # Follow-up: return all subarrays
    # T: O(n ^ 3)?
    # S: O(n ^ 2)
    def subarraySumF(self, nums: List[int], k: int) -> List[List[int]]:
        prefix_sum_subarrs = defaultdict(list)
        prefix_sum_subarrs[0] = [-1]  # IMPORTANT
        p_sum = 0

        res = []
        for i, num in enumerate(nums):
            p_sum += num
            prefix_sum_subarrs[p_sum].append(i)

            another_p_sum = p_sum - k
            if another_p_sum in prefix_sum_subarrs:
                for j in prefix_sum_subarrs[another_p_sum]:
                    res.append(nums[j + 1:i + 1])

        return res


# @lc code=end

