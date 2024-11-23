#
# @lc app=leetcode id=1344 lang=python3
#
# [1344] Angle Between Hands of a Clock
#

# @lc code=start
class Solution:
    # Math
    # T: O(1)
    # S: O(1)
    def angleClock(self, hour: int, minutes: int) -> float:
        angle_minute = minutes / 60 * 360
        angle_hour = (hour % 12) / 12 * 360 + minutes / 60 * (360 / 12)
        angle = abs(angle_minute - angle_hour)
        return angle if angle <= 180 else 360 - angle


# @lc code=end

