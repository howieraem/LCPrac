import math
from typing import List


class Solution:
    # 3D DP + memoized DFS
    # T: O(len(nums) * op1 * op2)
    # S: O(len(nums) * op1 * op2)
    def minArraySum(self, nums: List[int], k: int, op1: int, op2: int) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        memo = [[[-1] * (op2 + 1) for _ in range(op1 + 1)] for _ in range(n)]

        def dfs(i, op1, op2):
            if i == n:
                return 0
            
            if memo[i][op1][op2] != -1:
                return memo[i][op1][op2]

            ans = float('inf')
            
            # case 1: apply op1 only
            if op1 > 0:
                ans = min(ans, math.ceil(nums[i] / 2.) + dfs(i + 1, op1 - 1, op2))

            # case 2: apply op2 only
            if op2 > 0 and nums[i] >= k:
                ans = min(ans, nums[i] - k + dfs(i + 1, op1, op2 - 1))

            # apply both op1 and op2 if possible
            if op1 > 0 and op2 > 0:
                # case 3: op1 and then op2
                after_op1 = math.ceil(nums[i] / 2.)
                if after_op1 >= k:
                    ans = min(ans, after_op1 - k + dfs(i + 1, op1 - 1, op2 - 1))

                # case 4: op2 and then op1
                after_op2 = nums[i] - k
                if after_op2 >= 0:
                    ans = min(ans, math.ceil(after_op2 / 2.) + dfs(i + 1, op1 - 1, op2 - 1))

            # case 5: do nothing
            ans = min(ans, nums[i] + dfs(i + 1, op1, op2))

            memo[i][op1][op2] = ans
            return ans

        return dfs(0, op1, op2)
