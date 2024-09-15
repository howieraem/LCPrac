from typing import List

class Solution:
    # T: O(n)
    # S: O(n)
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        res = []
        seen = [False] * (len(nums) - 2)
        for x in nums:
            if seen[x]:
                res.append(x)
                if len(res) == 2:
                    return res
            seen[x] = True
        return res
