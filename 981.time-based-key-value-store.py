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
        if key not in self.map:
            return ""
        
        # According to the question specs, values are sorted by time
        values = self.map[key]

        # Special cases
        # if timestamp < values[0][0]:
        #     return ""
        # if timestamp >= values[-1][0]:
        #     return values[-1][1]

        # Find value at the latest time before timestamp,
        # upper bound binary search
        l, r = 0, len(values) - 1
        while l <= r:
            m = (l + r) >> 1
            mt = values[m][0]
            if mt <= timestamp:
                l = m + 1
            else:
                r = m - 1
        return "" if r < 0 else values[r][1]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
# @lc code=end

