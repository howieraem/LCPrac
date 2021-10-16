class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        if not k:
            return 1

        def f(num):
            ret = 0
            while num:
                ret += num % 10
                num //= 10
            return ret
        
        seen = [[False] * n for _ in range(m)]
        ans = 1
        
        '''
        # BFS solution, requires extra space for queue
        DIRN = (0, 1, 0)
        q = deque()
        q.append((0, 0))
        while len(q):
            i, j = q.popleft()
            for d in range(2):
                di, dj = DIRN[d:d + 2]
                ni, nj = i + di, j + dj
                if ni < m and nj < n and not seen[ni][nj] and f(ni) + f(nj) <= k:
                    seen[ni][nj] = True
                    q.append((ni, nj))
                    ans += 1
        return ans
        '''

        # 01 dp solution
        seen[0][0] = True
        for i in range(m):
            for j in range(n):
                if not (i or j) or f(i) + f(j) > k:
                    continue
                if i > 0:
                    seen[i][j] |= seen[i - 1][j]
                if j > 0:
                    seen[i][j] |= seen[i][j - 1]
                ans += seen[i][j]
        return ans
