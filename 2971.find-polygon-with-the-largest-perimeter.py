from typing import List

class Solution:
    # Sort + prefix sum or suffix sum
    # T: O(n * log(n))
    # S: O(n) timsort
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()

        # 2-pass solution: more intuitive
        perimeter_sum = sum(nums)
        for i in range(len(nums) - 1, 1, -1):
            sum_exclude_longest_side = perimeter_sum - nums[i]
            if sum_exclude_longest_side > nums[i]:
                # can form a polygon, and perimeter is largest
                return perimeter_sum
            perimeter_sum = sum_exclude_longest_side
        return -1   # impossible to form a polygon
    
        """
        # 1-pass solution
        # This can cover edge cases len(nums) <= 2
        ans = -1
        perimeter_sum = 0
        for x in nums:
            if x < perimeter_sum:
                ans = x + perimeter_sum
            perimeter_sum += x
        return ans
        """
