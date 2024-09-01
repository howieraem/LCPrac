from typing import List

class Solution:
    # T: O(m * n * 2 ^ n)
    # S: O(m * n * 2 ^ n)
    def maxScore(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        total = m * n

        vals_n_pos = [(grid[r][c], r, c) for r in range(m) for c in range(n)]
        vals_n_pos.sort(reverse=True)
        memo = dict()

        def dfs(vals_n_pos, v_idx, mask, memo):
            if v_idx == total:
                return 0
            cache_k = (v_idx, mask)
            cached = memo.get(cache_k, None)
            if cached is not None:
                return cached

            ans = 0
            v, r, c = vals_n_pos[v_idx]
            r_mask = 1 << r
            if r_mask & mask:  # row already visited
                ans += dfs(vals_n_pos, v_idx + 1, mask, memo)
            else:
                j = v_idx
                while j < total and vals_n_pos[j][0] == v:
                    # skip duplicate values
                    j += 1
                
                ans_incl_cur = v + dfs(vals_n_pos, j, mask | r_mask, memo)
                ans_excl_cur = dfs(vals_n_pos, v_idx + 1, mask, memo)
                ans = max(ans_incl_cur, ans_excl_cur)
            
            memo[cache_k] = ans
            return ans
        
        return dfs(vals_n_pos, 0, 0, memo)
