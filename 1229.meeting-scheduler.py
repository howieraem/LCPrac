#
# @lc app=leetcode id=1229 lang=python3
#
# [1229] Meeting Scheduler
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    '''
    # Solution 1: sweeping line (variant of prefix sum)
    # easier to generalize to more people
    # T: O((m + n) * log(m + n))
    # S: O(m + n)
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        mp = defaultdict(int)
        
        for s, e in slots1:
            mp[s] += 1  # interval start: +1
            mp[e] -= 1  # interval end: -1
        for s, e in slots2:
            mp[s] += 1
            mp[e] -= 1
        
        li = sorted(mp.items(), key=lambda x: x[0])
        
        i = 0
        cur = 0
        while i < len(li):
            cur += li[i][1]   # prefix sum
            # if cur == 0: all people busy

            if cur == 2:  # both people available
                if i + 1 < len(li):
                    if li[i + 1][0] - li[i][0] >= duration:
                        return [li[i][0] , li[i][0] + duration]
            i += 1

        return []
    '''
    
    # Solution 2: sorting + two pointer + interval + greedy
    # T: O(m * log(m) + n * log(n))
    # S: O(m + n)
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()

        m = len(slots1)
        n = len(slots2)
        i = 0
        j = 0
        while i < m and j < n:
            intersect_start = max(slots1[i][0], slots2[j][0])
            intersect_end = min(slots1[i][1], slots2[j][1])
            if intersect_end - intersect_start >= duration:
                return [intersect_start, intersect_start + duration]
                # if need all eligible intervals:
                # i += 1
                # j += 1

            # shift pointer based on end time comparison
            if slots1[i][1] < slots2[j][1]:
                i += 1
            else:
                j += 1

        return []

# @lc code=end

