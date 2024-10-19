#
# @lc app=leetcode id=170 lang=python3
#
# [170] Two Sum III - Data structure design
#

# @lc code=start
# Tradeoffs: read heavy vs write heavy
# - Read heavy (no. of find >> no. of add): 
#   - Consider precomputing sums and storing them at each add(); then find() is O(1)
#   - Space complexity can be high (up to O(n ^ 2)) to store all possible sums
# - Write heavy (no. of add >> no. of find): 
#   - Store the frequency of num at each add(); then find() is O(n)
#   - Space complexity O(n)
class TwoSum:
    # Write heavy approach
    # S: O(n)
    def __init__(self):
        self.map = dict()

    # T: O(1)
    def add(self, number: int) -> None:
        if number in self.map:
            self.map[number] += 1
        else:
            self.map[number] = 1 

    # T: O(n)
    def find(self, value: int) -> bool:
        for num1 in self.map:
            num2 = value - num1
            num2_cnt = self.map.get(num2, 0)
            if num1 != num2 and num2_cnt > 0:
                return True  # no. of pairs = num1_cnt * num2_cnt
            elif num1 == num2 and num2_cnt > 1:
                return True  # no. of pairs = (num2_cnt)C2 = num2_cnt * (num2_cnt - 1) / 2
        return False  # no. of pairs = 0

# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
# @lc code=end

