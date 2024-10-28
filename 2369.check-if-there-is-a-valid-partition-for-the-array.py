from typing import List

class Solution:
    # Fixed-size sliding window + DP
    # T: O(n)
    # S: O(1) state compression
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 2:
            return False
        if n == 2:
            return nums[0] == nums[1]
        
        # dp[i] means whether it's possible to partition s[:i].
        # As the max subarr len in conditions is 3, earlier dp states
        # are not useful at later iterations. Instead of allocating len(s) 
        # size to dp, we can fix dp at size 3 and apply sliding window.
        # Base cases:
        # dp[0] = True
        # dp[1] = False
        # dp[2] = nums[0] == nums[1]
        dp = [True, False, nums[0] == nums[1]]  # equivalent to dp[i - 2], dp[i - 1] and dp[i] if len(dp) = len(s)

        for r in range(2, n):
            # 2 equal elements, 3 equal elements, or 3 consecutive increasing elements
            dp_cur = (nums[r] == nums[r - 1] and dp[1]) or \
                     (nums[r] == nums[r - 1] == nums[r - 2] and dp[0]) or \
                     (nums[r] - nums[r - 1] == 1 and nums[r - 1] - nums[r - 2] == 1 and dp[0])

            # sliding window, rolling update of dp states
            dp[0] = dp[1]
            dp[1] = dp[2]
            dp[2] = dp_cur

            # possible early stop for very long string
            if not any(dp):
                return False

        return dp[2]
