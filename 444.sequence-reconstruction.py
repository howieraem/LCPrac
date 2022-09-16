#
# @lc app=leetcode id=444 lang=python3
#
# [444] Sequence Reconstruction
#
from typing import *

# @lc code=start
class Solution:
    # T: O(len(nums) + sum(len(seq) for seq in sequences))
    # S: O(len(nums))
    def sequenceReconstruction(self, nums: List[int], sequences: List[List[int]]) -> bool:
        n = len(nums)
        order = [0] * (n + 1)
        for i, x in enumerate(nums):
            if not (0 < x <= n):
                # not a permutation of [1, ..., n]
                return False
            order[x] = i

        pairs = [False] * n
        for seq in sequences:
            for i in range(len(seq)):
                if not (0 < seq[i] <= n):
                    # not a valid subseq
                    return False

                if i == 0:
                    if seq[i] == nums[0]:
                        pairs[0] = True
                else:
                    if order[seq[i - 1]] >= order[seq[i]]:
                        # Not a valid subseq
                        return False
        
                    # Every 2 consecutive elements in `nums` should be consecutive elements 
                    # in some seq from `sequences`
                    if order[seq[i - 1]] + 1 == order[seq[i]]:
                        pairs[order[seq[i]]] = True
                
        return all(pairs)

# @lc code=end

