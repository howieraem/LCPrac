from typing import List

class Solution:
    # T: O(n)
    # S: O(n)
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        # Constraint: 1 <= nums[i] <= len(nums)
        freq = [0] * len(nums)
        res = []
        
        for x in nums:
            if freq[x - 1] >= len(res):
                res.append([])
            
            res[freq[x - 1]].append(x)
            freq[x - 1] += 1
        
        return res
