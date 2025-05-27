#
# @lc app=leetcode id=1007 lang=python3
#
# [1007] Minimum Domino Rotations For Equal Row
#
from collections import List

# @lc code=start
class Solution:
    # Greedy
    # T: O(n)
    # S: O(1)
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n = len(tops)  # equals len(bottoms)

        # Idea: check whether either top_i or bottom_i equal to the first element of one of {tops, bottoms}
        def count_rot(ref: int):
            rot_top = 0
            rot_bottom = 0

            for i in range(n):
                if tops[i] != ref and bottoms[i] != ref:
                    return -1
                elif tops[i] != ref:
                    rot_top += 1
                elif bottoms[i] != ref:
                    rot_bottom += 1

            return min(rot_top, rot_bottom)
        
        ans = count_rot(tops[0])
        return ans if ans != -1 else count_rot(bottoms[0])


# @lc code=end

