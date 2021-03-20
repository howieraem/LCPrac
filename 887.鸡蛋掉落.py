#
# @lc app=leetcode.cn id=887 lang=python3
#
# [887] 鸡蛋掉落
#

# @lc code=start
class Solution:
    '''
    def superEggDrop(self, K: int, N: int) -> int:
        # 记忆化递归（与动态规划同复杂度）
        self.memo = {}
        return self.dp(K, N)

    def dp(self, k, n):
        if k == 1:
            return n
        if not n:
            return 0
        key = n * 100 + k
        if key in self.memo:
            return self.memo[key]
        
        ans = float('inf')
        l, r = 1, n
        while l <= r:
            mid = (l + r) >> 1
            case_broken = self.dp(k - 1, mid - 1)
            case_not_broken = self.dp(k, n - mid)
            if case_broken > case_not_broken:
                r = mid - 1
                ans = min(ans, case_broken + 1)
            else:
                l = mid + 1
                ans = min(ans, case_not_broken + 1)
            
        self.memo[key] = ans
        return ans
    '''

    def superEggDrop(self, K: int, N: int) -> int:
        # Strategy: find the number of trials m where dp[k][m] = n
        dp = [[0] * (N + 1) for _ in range(K + 1)]
        m = 0

        while dp[K][m] < N:
            m += 1
            for k in range(1, K + 1):
                dp[k][m] = (            # total number of levels n
                    dp[k][m - 1] +      # level above the current level where egg broken 
                    dp[k - 1][m - 1]    # level under the current level where egg not broken
                    + 1                 # current level
                )
        return m

    def superEggDrop(self, K: int, N: int) -> int:
        # Optimized space for the solution above
        dp = [0] * K
        m = 0

        while True:
            m += 1
            pre = 0
            for k in range(K):
                tmp = dp[k]
                dp[k] = dp[k] + pre + 1
                pre = tmp
                if dp[k] >= N:
                    return m
        
# @lc code=end

