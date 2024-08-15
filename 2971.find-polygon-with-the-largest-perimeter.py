from typing import List

class Solution:
    # T: O(n * log(n))
    # S: O(n) timsort
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()

        ans = -1
        perimeter_sum = 0

        # This can cover edge cases len(nums) <=2
        for x in nums:
            if x < perimeter_sum:
                ans = x + perimeter_sum
            perimeter_sum += x

        return ans
