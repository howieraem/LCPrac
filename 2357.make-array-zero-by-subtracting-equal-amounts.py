from typing import List

class Solution:
    # Hash map + Math + Greedy?
    # T: O(n)
    # S: O(n)
    def minimumOperations(self, nums: List[int]) -> int:
        """
        Elements with the same value will need the same number of operations,
        so we should deduplicate them.

        Each unique non-zero element in the array will require at least one operation 
        to reduce it to zero, no matter how we choose the elements in each operation. 
        Therefore, we can simplify the problem by counting the number of unique non-zero 
        elements in the array. Each unique non-zero element contributes at least one 
        to the total number of operations needed to reduce all elements to zero.
        """
        pos_nums = set()
        for x in nums:
            if x > 0:
                pos_nums.add(x)
        return len(pos_nums)   # alternatively, len(nums) - nums.count(0)
