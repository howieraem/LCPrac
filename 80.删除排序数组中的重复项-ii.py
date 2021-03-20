#
# @lc app=leetcode.cn id=80 lang=python3
#
# [80] 删除排序数组中的重复项 II
#
from typing import List

# @lc code=start
class Solution:
    def removeDuplicates(self, nums):
        """Solution: does not keep the original counts of each element. Overwrites if necessary."""
        # Initialize the counter and the second pointer.
        j, count = 1, 1
        
        # Start from the second element of the array and process
        # elements one by one.
        for i in range(1, len(nums)):
            # If the current element is a duplicate, 
            # increment the count.
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                # Reset the count since we encountered a different element
                # than the previous one
                count = 1
            # For a count <= 2, we copy the element over thus
            # overwriting the element at index "j" in the array
            if count <= 2:
                nums[j] = nums[i]
                j += 1
        return j


# @lc code=end
s = Solution()
n = [0,0,0,1,1,1,2,3]
i = s.removeDuplicates(n)
print(n[:i])
