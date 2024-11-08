#
# @lc app=leetcode id=777 lang=python3
#
# [777] Swap Adjacent in LR String
#

# @lc code=start
class Solution:
    # Advanced two pointers + greedy?
    # Omit the 'X', and check the relative positions of 'L' and 'R'
    # T: O(m + n)
    # S: O(1)
    def canTransform(self, start: str, end: str) -> bool:
        m = len(start)
        n = len(end)
        i = 0
        j = 0

        # Key observations:
        # - Replacing XL with LX implies moving L to the left by one
        # - Replacing RX with XR implies moving R to the right by one
        # - If we remove all the X in both strings, the resulting strings should be the same
        # - An L or R cannot move through another L or R
        while i < m or j < n:
            # Skip 'X'
            while i < m and start[i] == 'X':
                i += 1
            while j < n and end[j] == 'X':
                j += 1
            if i == m or j == n:
                break
            
            if start[i] != end[j]:
                return False
            
            # 'L' can only be swapped to the left
            if start[i] == 'L' and i < j:
                return False
            
            # 'R' can only be swapped to the right
            if start[i] == 'R' and i > j:
                return False
            
            i += 1
            j += 1
        
        return i == j
        
# @lc code=end

