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
        # Key assumption/constraint: values of the same key must be inserted in the order of timestamp,
        # so map[key] = [(t0, v0), (t1, v1), ...] is always sorted by timestamp
        self.map[key].append((timestamp, value))

    # T: O(log(n))
    def get(self, key: str, timestamp: int) -> str:
        # According to the question specs, values are sorted by time
        values = self.map.get(key, None)
        if not values:
            return ""

        # Find value at the latest time before timestamp,
        # i.e. rightmost binary search
        l, r = 0, len(values) - 1
        while l <= r:
            m = l + ((r - l) >> 1)
            if values[m][0] <= timestamp:
                l = m + 1
            else:
                r = m - 1
        return "" if r < 0 else values[r][1]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
# @lc code=end

