from typing import List

class Solution:
    # T: O(len(nums) * max(nums))
    # S: O(max(nums))
    def countOfPairs(self, nums: List[int]) -> int:
        N = len(nums)
        M = max(nums) + 1
        MOD = 1000000007
        
        # dp[i][j] means the number of pairs with length i + 1 and arr[i] = j.
        dp_i1 = [1] * M
        
        # Monotonic constraints: 
        # arr1[i] >= arr1[i - 1]
        # arr2[i] = nums[i] - arr1[i] <= nums[i - 1] - arr[i - 1] = arr2[i - 1]
        # Rearrange:
        # arr1[i] - arr1[i - 1] >= nums[i] - nums[i - 1]
        # Thus:
        # arr1[i] - arr1[i - 1] >= max(0, nums[i] - nums[i - 1])
        for i in range(1, N):
            d = max(0, nums[i] - nums[i - 1])
            dp_i = [0] * M
            for j in range(d, nums[i] + 1):
                # dp[i][j] = dp[i][j - 1] + dp[i - 1][j - d]
                if j == 0:
                    dp_i[j] = dp_i1[0] % MOD
                else:
                    dp_i[j] = (dp_i[j - 1] + dp_i1[j - d]) % MOD
            dp_i1 = dp_i

        return sum(dp_i1) % MOD
