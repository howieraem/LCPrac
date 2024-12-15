class Solution:
    # backtracking
    # T: O(3 * (9 - 1) ^ n)
    # S: O(n)
    def numberOfPatterns(self, m: int, n: int) -> int:
        passes = [[0] * 10 for _ in range(10)]   # use 0 to represent no pass exists
        
        # boundary paths
        passes[1][3] = passes[3][1] = 2
        passes[1][7] = passes[7][1] = 4
        passes[3][9] = passes[9][3] = 6
        passes[7][9] = passes[9][7] = 8

        # paths passing through the center
        passes[1][9] = passes[9][1] = 5
        passes[3][7] = passes[7][3] = 5
        passes[2][8] = passes[8][2] = 5
        passes[4][6] = passes[6][4] = 5

        vis = [False] * 10

        def backtrack(cur_digit, cur_len):
            # base cases
            if cur_len > n:
                return 0
            cnt = cur_len >= m   # m <= cur_len <= n

            vis[cur_digit] = True
            cur_len += 1
            for i in range(1, 10):
                if not vis[i] and (passes[cur_digit][i] == 0 or vis[passes[cur_digit][i]]):
                    # accumulate iff path is valid
                    cnt += backtrack(i, cur_len)
            vis[cur_digit] = False
            return cnt
                
        ans = (backtrack(1, 1) << 2)   # starting at 1, 3, 7, 9 are equivalent
        ans += (backtrack(2, 1) << 2)   # starting at 2, 4, 6, 8 are equivalent
        ans += backtrack(5, 1)
        return ans
