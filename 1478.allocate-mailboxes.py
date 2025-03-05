#
# @lc app=leetcode id=1478 lang=python
#
# [1478] Allocate Mailboxes
#

# @lc code=start
class Solution(object):
    # Memoized DFS + Top-down 3D DP
    # T: O(n ^ 3)
    # S: O(n ^ 2)
    def minDistance(self, houses, k):
        """
        :type houses: List[int]
        :type k: int
        :rtype: int
        """
        INF = float('inf')

        # Partition houses into k groups, and place a mailbox at the median of each group to minimize distance.
        houses.sort()

        n = len(houses)

        # Calculate the cost matrix, cost[i][j] means total travel distances of houses[i...j]
        # to the median positioned mailbox between i and j
        costs = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(i, n):
                m = houses[(i + j) >> 1]
                for h in range(i, j + 1):
                    costs[i][j] += abs(m - houses[h])

        # memo[k][i] means minimum cost for splitting houses[i:] into k groups
        memo = [[None] * n for _ in range(k + 1)]

        def dfs(k, i):
            if k == 0 and i == n:
                return 0
            if k == 0 or i == n:
                return INF
            
            if memo[k][i] is not None:
                return memo[k][i]

            ans = INF
            for j in range(i, n):
                ans = min(ans, costs[i][j] + dfs(k - 1, j + 1))

            memo[k][i] = ans
            return ans
        
        return dfs(k, 0)


# @lc code=end

