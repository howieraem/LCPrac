from typing import List

class Solution:
    # T: O(n)
    # S: O(n)
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        # Constraint: 1 <= nums[i] <= len(nums)
        freqs = [0] * len(nums)  # or use a hash map if no constraint on value
        res = []
        
        for x in nums:
            xi = x - 1

            # Whenever a number reappears, prepare a new row
            if freqs[xi] >= len(res):
                res.append([])
            
            # Row index equals the current count of the number
            res[freqs[xi]].append(x)

            freqs[xi] += 1
        
        return res
