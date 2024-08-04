#
# @lc app=leetcode id=1963 lang=python3
#
# [1963] Minimum Number of Swaps to Make the String Balanced
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def minSwaps(self, s: str) -> int:
        mismatch = 0
        for c in s:
            if c == '[':
                mismatch += 1
            else:
                if mismatch > 0:
                    # ignore all valid pairs
                    mismatch -= 1

        # Why divide by 2: optimal approach is to balance 2 sets of brackets 
        # at a time using 1 swap
        return (mismatch + 1) >> 1  
        
# @lc code=end

