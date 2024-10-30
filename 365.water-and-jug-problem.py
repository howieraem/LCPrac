#
# @lc app=leetcode id=365 lang=python3
#
# [365] Water and Jug Problem
#
from collections import deque

# @lc code=start
class Solution:
    # BFS, non-math method
    # This can also restore the number and the sequence of operations
    # T: O(x + y)
    # S: O(x + y)
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        if x + y < target:
            return False
    
        # make y the larger jug
        if x > y:
            x, y = y, x
        
        # set the initial state will empty jars
        queue = deque()   # queue of current water amount in two jugs (x, y)
        queue.append((0, 0))   # start with both empty
        visited = set((0, 0))
        while len(queue) > 0:
            a, b = queue.popleft()
            if a + b == target:
                return True
            
            states = set()
            
            states.add((x, b)) # fill jar x
            states.add((a, y)) # fill jar y
            states.add((0, b)) # empty jar x
            states.add((a, 0)) # empty jar y
            states.add((min(x, b + a), max(0, b - (x - a))))   # pour jar y to fill jar x
            states.add((max(0, a - (y - b)), min(b + a, y)))   # pour jar x to fill jar y

            for state in states:
                if state in visited:
                    continue
                queue.append(state)
                visited.add(state)
                
        return False

# @lc code=end

