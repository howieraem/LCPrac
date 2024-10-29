#
# @lc app=leetcode id=962 lang=python3
#
# [962] Maximum Width Ramp
#
from typing import List

# @lc code=start
class Solution:
    # Variant of mono-stack
    # T: O(n)
    # S: O(n)
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        
        # stores indices of corresponding numbers ordered DESC
        st = []

        for i in range(n):
            if len(st) == 0 or nums[st[-1]] > nums[i]:
                # push the index of a smaller number
                st.append(i)
            # else there's no need to push to stack because 
            # nums[st[-1]] can always form a longer ramp

        ans = 0

        # Iterate reversely, because if nums[i - 1] <= nums[i],
        # nums[i] will always form a longer ramp than nums[i - 1]
        for i in range(n - 1, -1, -1):
            while len(st) > 0 and nums[st[-1]] <= nums[i]:
                ans = max(ans, i - st.pop())
        
        return ans

        
# @lc code=end

