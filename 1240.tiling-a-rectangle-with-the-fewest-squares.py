#
# @lc app=leetcode id=1240 lang=python3
#
# [1240] Tiling a Rectangle with the Fewest Squares
#

# @lc code=start
class Solution:
    # T: O(m ^ k), k := optimal moves ?
    def tilingRectangle(self, n: int, m: int) -> int:
        ans = m * n

        # Filling order: from bottom left to top right.
        def backtrack(heights, moves):
            nonlocal ans
            if all(h == n for h in heights):
                # The rectangle is tiled
                ans = min(ans, moves)
                return
            if moves >= ans:
                return
            
            # Find minimum height and its index
            min_h = heights[0]
            min_idx = 0
            for i in range(1, len(heights)):
                if heights[i] < min_h:
                    min_h = heights[i]
                    min_idx = i
            
            # Find the maximum allowed width of a square
            max_idx = min_idx + 1
            while max_idx < m and heights[max_idx] == min_h:
                max_idx += 1
            max_width = min(max_idx - min_idx, n - min_h)
            
            for w in range(max_width, 0, -1):
                # Put a square
                for i in range(min_idx, min_idx + w):
                    heights[i] += w
                backtrack(heights, moves + 1)
                # Undo putting the square
                for i in range(min_idx, min_idx + w):
                    heights[i] -= w

        backtrack([0] * m, 0)
        return ans

# @lc code=end

