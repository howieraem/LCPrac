#
# @lc app=leetcode id=551 lang=python3
#
# [551] Student Attendance Record I
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def checkRecord(self, s: str) -> bool:
        na = nl = 0
        for c in s:
            na += c == 'A'
            if c == 'L':
                nl += 1
            else:
                nl = 0
            if na >= 2 or nl >= 3:
                return False
        return True
        
# @lc code=end

