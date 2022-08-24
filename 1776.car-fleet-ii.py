#
# @lc app=leetcode id=1776 lang=python3
#
# [1776] Car Fleet II
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        N = len(cars)
        stack = []
        res = [-1] * N

        # Mono-stack (of car indices) with decreasing collision time
        for i in range(N - 1, -1, -1):
            while len(stack) > 0 and (cars[stack[-1]][1] >= cars[i][1] or 
                                      0 < res[stack[-1]] <= self.get_collision_time(cars[stack[-1]], cars[i])):
                # cars[stack[-1]] and cars[i] will not collide
                stack.pop()

            if len(stack) > 0:
                res[i] = self.get_collision_time(cars[stack[-1]], cars[i])
            stack.append(i)
        return res

    @staticmethod
    def get_collision_time(car_front: List[int], car_rear: List[int]):
        # diff_pos / diff_speed
        # Assuming rear car's speed is greater than front car's speed
        return (car_front[0] - car_rear[0]) / (car_rear[1] - car_front[1])

# @lc code=end

