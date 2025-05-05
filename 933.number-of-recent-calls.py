#
# @lc app=leetcode id=933 lang=python3
#
# [933] Number of Recent Calls
#
from collections import deque

# @lc code=start
# Queue + Sliding window
# S: O(WINDOW_SZ)
class RecentCounter:
    WINDOW_SZ = 3000

    # T: O(1)
    def __init__(self):
        self.q = deque()

    # T: O(WINDOW_SZ)
    def ping(self, t: int) -> int:
        self.q.append(t)
        l = t - self.WINDOW_SZ
        while self.q[0] < l:
            self.q.popleft()
        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
# @lc code=end

