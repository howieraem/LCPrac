#
# @lc app=leetcode id=380 lang=python3
#
# [380] Insert Delete GetRandom O(1)
#
import random

# @lc code=start
# All T amortized to O(1)
class RandomizedSet:

    def __init__(self):
        self.dict = {}
        self.vals = []

    def insert(self, val: int) -> bool:
        if val in self.dict:
            return False
        self.dict[val] = len(self.vals)
        self.vals.append(val)
        return True

    def remove(self, val: int) -> bool:        
        idx = self.dict.get(val, -1)
        if idx == -1:
            return False
        
        # replace val to be removed with the last inserted val
        last_val = self.vals[-1]
        self.vals[idx] = last_val
        self.dict[last_val] = idx

        # remove values
        self.vals.pop()
        self.dict.pop(val)
        return True

    def getRandom(self) -> int:
        return self.vals[random.randrange(0, len(self.vals))]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @lc code=end

