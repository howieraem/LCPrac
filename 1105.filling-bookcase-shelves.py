#
# @lc app=leetcode id=1105 lang=python3
#
# [1105] Filling Bookcase Shelves
#
from typing import List

# @lc code=start
class Solution:
    '''
    # Top-down
    # T: O(n * shelfWidth)
    # S: O(n * shelfWidth)
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        memo = [[0] * (shelfWidth + 1) for _ in range(n)]

        def dfs(i, w, h):
            if i == n:
                return h
            if memo[i][w] == 0:
                memo[i][w] = h + dfs(i + 1, books[i][0], books[i][1])  # create a new row with the current book
                if w + books[i][0] <= shelfWidth:  # add the current book to the existing row and update the maximum height
                    memo[i][w] = min(memo[i][w], dfs(i + 1, w + books[i][0], max(h, books[i][1])))
            return memo[i][w]

        return dfs(0, 0, 0)
    '''

    # Bottom-up
    # T: O(n ^ 2)
    # S: O(n)
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        dp = [float('inf')] * (n + 1)  # dp[i] means the minimum heights with i books
        dp[0] = 0
        for i in range(1, n + 1):
            # Create a new row
            w = h = 0
            for j in range(i, 0, -1):
                w += books[j - 1][0]
                if w > shelfWidth:
                    break  # row is full, stop
                h = max(h, books[j - 1][1])  # update the maximum height of the row
                dp[i] = min(dp[i], dp[j - 1] + h)  # update the total height of rows created (or books used) so far
        return dp[n]

# @lc code=end

