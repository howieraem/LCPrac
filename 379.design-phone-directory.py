#
# @lc app=leetcode id=379 lang=python3
#
# [379] Design Phone Directory
#

# @lc code=start
# Simulate a linked list (queue) with an array
# S: O(n)
class PhoneDirectory:
    # T: O(n)
    def __init__(self, maxNumbers: int):
        self.next = [0] * maxNumbers
        for i in range(maxNumbers):
            # Index modulo trick is feasible here because only next one is needed
            self.next[i] = (i + 1) % maxNumbers  # next available number index
        self.p = 0

    # T: O(1)
    def get(self) -> int:
        if self.next[self.p] == -1:
            return -1
        cur_p = self.p
        self.p = self.next[self.p]
        self.next[cur_p] = -1
        return cur_p

    # T: O(1)
    def check(self, number: int) -> bool:
        return self.next[number] != -1        

    # T: O(1)
    def release(self, number: int) -> None:
        if self.next[number] != -1:
            return
        self.next[number] = self.p
        self.p = number

# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
# @lc code=end

