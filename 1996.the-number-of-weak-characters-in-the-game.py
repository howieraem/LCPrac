#
# @lc app=leetcode id=1996 lang=python3
#
# [1996] The Number of Weak Characters in the Game
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n * log(n))
    # S: O(n)
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        # Sort by attack ASC and then defense DSC
        properties.sort(key=lambda x: (x[0], -x[1]))

        # At this point, any character in properties must be weaker or on par with 
        # its next character for attack.

        ans = 0

        stack = []
        for _, d in properties:
            # stack bottom is the current maximum defense strength
            while len(stack) and stack[-1] < d:
                stack.pop()
                ans += 1
            stack.append(d)

        return ans

# @lc code=end

