class Solution:
    # array
    # T: O(n * k), k := 3
    # S: O(k)
    def largestGoodInteger(self, nums: str) -> str:
        n = len(nums)
        digit = ''
        for i in range(n - 2):
            if nums[i] == nums[i + 1] == nums[i + 2]:
                digit = max(digit, nums[i])
        return digit * 3  # this also covers empty string case in python
