#
# @lc app=leetcode id=229 lang=python3
#
# [229] Majority Element II
#
from typing import List

# @lc code=start
class Solution:
    # Boyer-Moore Majority Vote Algo
    # T: O(n * k), k = 3
    # S: O(k)
    def majorityElement(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        
        MAJOR_COUNT = len(nums) // 3

        # Find possible major candidates.
        # As k = 3, there is at most 2 eligible candidates 
        # and we need k - 1 = 2 counters.
        # The rationale is that we rule triplets (Tuple3 with distinct numbers) out,
        # and then the remaining candidates can be major.
        cand1 = cand2 = nums[0]
        cnt1 = cnt2 = 0
        for x in nums:
            if x == cand1:
                cnt1 += 1
            elif x == cand2:
                cnt2 += 1
            elif cnt1 == 0:
                cand1 = x
                cnt1 = 1
            elif cnt2 == 0:
                cand2 = x
                cnt2 = 1
            else:
                cnt1 -= 1
                cnt2 -= 1

        # Check if the actual count satisfies
        cnt1 = cnt2 = 0
        for x in nums:
            if x == cand1:
                cnt1 += 1
            elif x == cand2:
                cnt2 += 1
        
        res = []
        if cnt1 > MAJOR_COUNT:
            res.append(cand1)
        if cnt2 > MAJOR_COUNT:
            res.append(cand2)
        return res

# @lc code=end

