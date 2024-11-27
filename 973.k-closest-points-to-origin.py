#
# @lc app=leetcode id=973 lang=python3
#
# [973] K Closest Points to Origin
#
from random import randint
from typing import *

# @lc code=start
class Solution:
    # Quick select without extra heap space
    # We don't care the order of the k points, and assume input points can be modified
    # T: O(n ^ 2) worst, O(n) best/average
    # S: O(1) iterative
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        n = len(points)
        if k == n:
            return points

        l, r = 0, n - 1
        while l < r:
            m = self.partition(points, l, r)
            if m > k:
                r = m - 1
            elif m < k:
                l = m + 1
            else:
                break
        return points[:k]
    
    # This method modifies `points` in place
    @staticmethod
    def partition(points, l, r):
        p = randint(l, r)
        # Swap pivot point to the left
        points[l], points[p] = points[p], points[l]

        pivot = Solution.dist(points[l])
        i, j = l + 1, r

        while i <= j:
            # Skip indices if the distances already meet the requirement 
            # that smaller distances should be on the left of pivot and 
            # the larger distances should be on the right of pivot
            if Solution.dist(points[i]) <= pivot:
                i += 1
                continue
            if Solution.dist(points[j]) >= pivot:
                j -= 1
                continue
            
            # while i < r and Solution.dist(points[i]) <= pivot:
            #     i += 1
            # while j > l and Solution.dist(points[j]) >= pivot:
            #     j -= 1
            # if i >= j:
            #     break
            
            points[i], points[j] = points[j], points[i]
            i += 1
            j -= 1
        
        # Now j should be the new index of pivot, so that distance numbers on the left
        # are less than or equal to pivot and distance numbers on the right are greater 
        # than or equal to pivot. 
        points[l], points[j] = points[j], points[l]
        return j

    @staticmethod
    def dist(p):
        return p[0] * p[0] + p[1] * p[1]

# @lc code=end

