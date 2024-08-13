from typing import List

class Solution:
    # T: O(n * log(n))
    # S: O(n) sort worst case
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()

        res = []
        for i in range(0, len(nums) - 2, 3):
            if nums[i + 2] - nums[i] > k:
                return []
            res.append(nums[i:i+3])
        return res
