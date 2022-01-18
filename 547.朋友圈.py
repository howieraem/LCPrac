#
# @lc app=leetcode.cn id=547 lang=python3
#
# [547] 朋友圈
#

# @lc code=start
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n, cnt = len(M), 0
        self.visited = [False] * n
        for i in range(n):
            if self.visited[i]:
                continue
            self.__dfs(M, i)
            cnt += 1
        return cnt

    def __dfs(self, M, i):
        self.visited[i] = True
        for j in range(len(M)):
            if M[i][j] and not self.visited[j]:
                self.__dfs(M, j)

# @lc code=end

