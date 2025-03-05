import math
from typing import *

class Solution:
    # Math + Hash map
    # T: O(n)
    # S: O(n)
    def minimumOperations(self, nums: List[int]) -> int:
        st = set()

        # Iterate backwards and find the first duplicate element and its index,
        # then it needs ceil((idx + 1) / 3) operations
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] in st:
                return math.ceil((i + 1) / 3.)
            st.add(nums[i])

        return 0
