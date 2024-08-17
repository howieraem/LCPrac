#
# @lc app=leetcode id=735 lang=python3
#
# [735] Asteroid Collision
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1) excl. res
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = []
        for x in asteroids:
            if x > 0:
                # e.g. [a, b], a < 0, b > 0, never collide
                res.append(x)
            else:
                while len(res) > 0 and res[-1] > 0 and res[-1] < -x:
                    # e.g. [a, b], a > 0, b < 0, abs(a) < abs(b)  
                    res.pop()
                
                if len(res) == 0 or res[-1] < 0:
                    # Two asteroids moving in the same direction will never meet
                    res.append(x)
                elif res[-1] == -x:
                    # Same size, opposite directions, both explode
                    res.pop()
        
        return res
        
# @lc code=end

