#
# @lc app=leetcode id=948 lang=python3
#
# [948] Bag of Tokens
#
from typing import List

# @lc code=start
class Solution:
    # Greedy + two pointers
    # T: O(n * log(n))
    # S: O(n) timsort
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
    
        # Greedy: To survive as many rounds as possible,
        # - play face-up for the smaller tokens
        # - play face-down for the larger tokens
        l = 0
        r = len(tokens) - 1
        cur_pts = 0
        ans = 0
        while l <= r:
            if power >= tokens[l]:  # face-up
                power -= tokens[l]
                cur_pts += 1
                ans = max(ans, cur_pts)
                l += 1
            elif cur_pts > 0:       # face-down
                power += tokens[r]
                cur_pts -= 1
                r -= 1
            else:  # lose
                break
        return ans
                


# @lc code=end

