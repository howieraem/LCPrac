from typing import List

class Solution:
    # two pointers
    # T: O(n)
    # S: O(1)
    def minimumOperations(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        ans = 0

        while l < r:
            if nums[l] == nums[r]:
                l += 1
                r -= 1
            else:
                # Operate on the left if current leftmost two elements are less,
                # otherwise operate on the right.
                if nums[l] + nums[l + 1] < nums[r] + nums[r - 1]:
                    nums[l + 1] += nums[l]
                    l += 1
                else:
                    nums[r - 1] += nums[r]
                    r -= 1
                ans += 1
        
        return ans
