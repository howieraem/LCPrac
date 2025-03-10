#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start
"""
# Solution with auxiliary stack
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = [float('inf')]

    def push(self, x: int) -> None:
        self.stack.append(x)
        self.min_stack.append(min(x, self.min_stack[-1]))

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]

"""
# Solution without pushing a copy of min every time
# stack + tracking of minimum
# S: O(n)
class MinStack:
    # T: O(1)
    def __init__(self):
        self.stack = []
        self.min = float('inf')

    # T: O(1)
    def push(self, x: int) -> None:
        if x <= self.min:   
            # append last min if a new min is found; note `<=`
            self.stack.append(self.min)
            self.min = x
        self.stack.append(x)

    # T: O(1)
    def pop(self) -> None:
        if self.stack.pop() == self.min:
            # recover the last min
            self.min = self.stack.pop()

    # T: O(1)
    def top(self) -> int:
        return self.stack[-1]

    # T: O(1)
    def getMin(self) -> int:
        return self.min



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

