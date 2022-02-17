#
# @lc app=leetcode id=353 lang=python3
#
# [353] Design Snake Game
#
from collections import deque
from typing import *

# @lc code=start
class SnakeGame:
    # S: O(n), n := len(food)
    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.w, self.h = width, height
        self.body = deque()
        self.set = set()
        self.score = 0
        self.food = food
        self.food_i = 0  # as food is not a set, use an index to mark visited

        self.body.append((0, 0))
        self.set.add((0, 0))

    # T: O(1)
    def move(self, direction: str) -> int:
        if self.score == -1:
            return -1
        r, c = self.body[0]
        if direction == 'U':
            r -= 1
        elif direction == 'D':
            r += 1
        elif direction == 'L':
            c -= 1
        else:
            c += 1
        new_head = (r, c)

        # Try moving
        pre_tail = self.body.pop()
        self.set.remove(pre_tail)

        if r < 0 or r >= self.h or c < 0 or c >= self.w or new_head in self.set:
            # out of bound, or snake head collides with body
            self.score = -1
            return -1
        
        self.set.add(new_head)
        self.body.appendleft(new_head)

        if self.food_i < len(self.food) and r == self.food[self.food_i][0] and c == self.food[self.food_i][1]:
            # food eaten, snake length + 1, add the old snake tail back 
            self.set.add(pre_tail)
            self.body.append(pre_tail)
            self.food_i += 1
            self.score += 1
            return self.score

        # normal move (no food eaten)
        return self.score

# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)
# @lc code=end

