class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == i:
                i += 1
                continue
            if nums[nums[i]] == nums[i]:
                # Numbers equal at indices nums[i] and i,
                # a duplicate is found
                return nums[i]
            # Swap the number to where the index equals the number itself
            nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1
