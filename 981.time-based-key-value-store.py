#
# @lc app=leetcode id=981 lang=python3
#
# [981] Time Based Key-Value Store
#
from collections import defaultdict
from typing import *

# @lc code=start
class TimeMap:

    def __init__(self):
        self.map = defaultdict(list)

    # T: O(1)
    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))

    # T: O(log(n))
    def get(self, key: str, timestamp: int) -> str:
        # According to the question specs, values are sorted by time
        values = self.map.get(key, None)
        if not values:
            return ""

        # Find value at the latest time before timestamp,
        # i.e. rightmost binary search
        l, r = 0, len(values)
        while l < r:
            m = (l + r) >> 1
            mt = values[m][0]
            if mt <= timestamp:
                l = m + 1
            else:
                r = m
        return "" if l <= 0 else values[l - 1][1]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
# @lc code=end

