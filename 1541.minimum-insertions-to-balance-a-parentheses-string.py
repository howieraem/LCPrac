#
# @lc app=leetcode id=1541 lang=python3
#
# [1541] Minimum Insertions to Balance a Parentheses String
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def minInsertions(self, s: str) -> int:
        # '(' corresponds to '))'
        r_needed = 0  # incr by 2 for every '('
        l_missing = 0  # incr by 1 for every '(' missing
        r_missing = 0  # incr by 1 for every ')' missing

        for c in s:
            if c == '(':
                if (r_needed & 1) != 0:
                    # example: "...()(..."
                    r_missing += 1
                    r_needed -= 1
                r_needed += 2
            else:
                r_needed -= 1
                if r_needed < 0:
                    # example: ")..."
                    l_missing += 1
                    r_needed += 2
        
        return l_missing + r_missing + r_needed


# @lc code=end

