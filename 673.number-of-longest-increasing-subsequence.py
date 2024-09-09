#
# @lc app=leetcode id=673 lang=python3
#
# [673] Number of Longest Increasing Subsequence
#
from typing import List

# @lc code=start
class Solution:
    # DP
    # T: O(n ^ 2)
    # S: O(n)
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)

        # lens[i] means len of longest subseq for nums[:i]
        lens = [1] * n

        # cnts[i] means count of longest subseq for nums[:i]  
        cnts = [1] * n

        max_len = 1

        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    new_len = lens[j] + 1
                    if new_len > lens[i]:
                        lens[i] = new_len
                        cnts[i] = cnts[j]
                    elif new_len == lens[i]:
                        # IMPORTANT: there are more subseqs of the same len
                        cnts[i] += cnts[j]
            max_len = max(max_len, lens[i])

        ans = 0
        for i in range(n):
            if lens[i] == max_len:
                ans += cnts[i]
        return ans


# @lc code=end

