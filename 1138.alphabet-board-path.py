#
# @lc app=leetcode id=1138 lang=python3
#
# [1138] Alphabet Board Path
#

# @lc code=start
class Solution:
    # T: O(len(target) * (m + n)), m := 6, n := 5
    # S: O(len(target) * (m + n)) for the intermediate list of strings (may be considered O(1) if string is mutable like in C++)
    def alphabetBoardPath(self, target: str) -> str:
        n = 5  # the maximum number of chars in a row
        pre_r = pre_c = 0
        res = []
        for ch in target:
            # Find the position of the character
            ci = ord(ch) - ord('a')
            r = ci // n
            c = ci % n

            # Find the direction and distance of the move
            dr = r - pre_r
            dc = c - pre_c
            # IMPORTANT: For 'z', cannot move left or right on that row. Thus, 
            # need to move up before moving right and move left before moving down.
            if dr < 0:
                res.append("U" * -dr)

            if dc > 0:
                res.append("R" * dc)
            else:
                res.append("L" * -dc)

            if dr > 0:
                res.append("D" * dr)

            # Record the char
            res.append('!')

            # Update previous row and col
            pre_r, pre_c = r, c
        
        return "".join(res)

        
# @lc code=end

