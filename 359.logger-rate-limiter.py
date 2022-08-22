#
# @lc app=leetcode id=359 lang=python3
#
# [359] Logger Rate Limiter
#
import threading

# @lc code=start
# Intuitive solution: one hash map, but may use too much memory.
# Optimization: keep messages for at most 20 seconds.

# T: O(1)
# S: O(1)
class Logger:
    def __init__(self):
        self.last_seen_t = 0
        self.cur = dict()  # stores [last_seen_t, last_seen_t + 10)
        self.pre = dict()  # stores [last_seen_t + 10, last_seen_t + 20)
        # self.lock = threading.Lock()  # simulates parallelism

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        # self.lock.acquire()

        diff = timestamp - self.last_seen_t
        if diff >= 20:
            self.pre.clear()
            self.cur.clear()
            self.last_seen_t = timestamp
        elif diff >= 10:
            # Must assign self.cur to a new dict. clear() won't work because
            # self.pre copies the reference.
            self.pre = self.cur
            self.cur = {}
            self.last_seen_t = timestamp

        if message in self.cur:
            return False
        if message in self.pre and timestamp - self.pre[message] < 10:
            return False
        self.cur[message] = timestamp

        # self.lock.release()
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
# @lc code=end

