#
# @lc app=leetcode id=780 lang=python3
#
# [780] Reaching Points
#

# @lc code=start
class Solution:
    # If we start from (sx, sy), it will be hard to find (tx, ty).
    # If we start from (tx, ty), we can find only one path to go back to (sx, sy).
    # T: O(log(min(tx, ty)))
    # S: O(1)
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while sx < tx and sy < ty:
            if tx < ty:
                ty %= tx
            else:
                tx %= ty
        # Check if we reduce the target point to (x, y + kx) or (x + ky, y)
        return sx == tx and sy <= ty and (ty - sy) % sx == 0 or \
               sy == ty and sx <= tx and (tx - sx) % sy == 0


# @lc code=end

