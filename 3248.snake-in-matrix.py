from typing import List

class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        i = j = 0
        
        for cmd in commands:
            if cmd == "UP" and i > 0:
                i -= 1
            elif cmd == "RIGHT" and j < n:
                j += 1
            elif cmd == "DOWN" and i < n:
                i += 1
            elif cmd == "LEFT" and j > 0:
                j -= 1
        
        return i * n + j
