#
# @lc app=leetcode id=359 lang=python3
#
# [359] Logger Rate Limiter
#
import threading

# @lc code=start
# Intuitive solution: one hash map, but may use too much memory.
# Optimization: keep messages for at most 20 seconds.
# We are storing 0-10 seconds in one hash map (cur) and 10-20 seconds in another hash map (pre)
# and when are pretty sure we lapsed the time of 10 seconds calculated using the current timestamp, 
# pre is being cleared and cur initialized with a new hash map

# T: O(1)
# S: O(m), m := the number of messages received within 20 secs.
class Logger:
    def __init__(self):
        self.thres = 10
        self.start_time = 0   # global, for all msgs, updated at most once every 10s
        self.cur = dict()  # k: msg, v: timestamp in [start_time, start_time + 10)
        self.pre = dict()  # k: msg, v: timestamp in [start_time + 10, start_time + 20)
        # self.lock = threading.Lock()  # simulates parallelism

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        # self.lock.acquire()

        if self.start_time + self.thres <= timestamp:
            # latest timestamp is just outside the deduplication time window
            self.start_time = timestamp
            self.pre = self.cur   # reference, not deep copy
            self.cur = {}

        if message in self.cur:
            return False
        message_prev_start_time = self.pre.get(message, None)

        # we need a secondary check here because self.start_time is updated at most once every 10s
        if message_prev_start_time is not None and message_prev_start_time + self.thres > timestamp:
            # still in the deduplication time window
            return False
        
        self.cur[message] = timestamp

        # self.lock.release()
        return True

# Alternative solution if rate is customizable: use a queue to store timestamps, and hash map(s) 

# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
# @lc code=end

