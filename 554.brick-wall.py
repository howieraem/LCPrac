#
# @lc app=leetcode id=554 lang=python3
#
# [554] Brick Wall
#
from typing import List
from collections import defaultdict

# @lc code=start
class Solution:
    # T: O(m * n), m := the number of rows, n := the number of bricks per row
    # S: O(m * n)
    def leastBricks(self, wall: List[List[int]]) -> int:
        width_sum_count = defaultdict(int)
        for row in wall:
            width_sum = 0

            # exclude the last brick, because the left and right boundaries are trivial solutions
            for i in range(len(row) - 1):  
                width_sum += row[i]
                width_sum_count[width_sum] += 1

        # note edge case: every row contains only one brick
        width_sum_max_rows = max(width_sum_count.values()) if len(width_sum_count) > 0 else 0

        # the answer equals the number of rows minus the maximum number of rows where bricks ends on the same edge
        return len(wall) - width_sum_max_rows  

        
# @lc code=end

