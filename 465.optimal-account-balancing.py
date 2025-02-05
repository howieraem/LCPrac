#
# @lc app=leetcode id=465 lang=python3
#
# [465] Optimal Account Balancing
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    # Memoized DFS + DP + bit manipulation
    # T: O(n * 2 ^ n)
    # S: O(2 ^ n)
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balances = defaultdict(int)
        for u, v, amount in transactions:
            balances[u] += amount
            balances[v] -= amount

        debts = [x for x in balances.values() if x != 0]
        n = len(debts)

        """
        Find m, the max number of disjoint sets where each set s has sum(s) == 0.
        Each of these sets CANNOT be divided to setA and setB where sum(setA) == sum(setB) == 0.
        For such each set we need len(s) - 1 transactions to settle the debt.
            ans = len(s_1) - 1 + len(s_2) - 1 + ... + len(s_m) - 1
            ans = len(s_1) + len(s_2) + ... + len(s_m) - 1 * m
        The final answer is n - m.
        """

        # k: bitmask representing what people are involved when building the sets, 
        # v: the corresponding max number of disjoint sets where each set has zero balance sum. 
        memo = [-1] * (1 << n)  
        memo[0] = 0

        def dfs(mask):
            if memo[mask] != -1:
                return memo[mask]
            
            balance_sum = 0
            ans = 0

            # remove one person at a time
            for i in range(n):
                person_mask = 1 << i
                if mask & person_mask:
                    balance_sum += debts[i]
                    ans = max(ans, dfs(mask ^ person_mask))  # use XOR to remove the person

            memo[mask] = ans + (balance_sum == 0)
            return memo[mask]
        
        return n - dfs((1 << n) - 1)

# @lc code=end

