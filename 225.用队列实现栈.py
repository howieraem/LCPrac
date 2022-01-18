#
# @lc app=leetcode.cn id=225 lang=python3
#
# [225] 用队列实现栈
#
from collections import deque

# @lc code=start
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = deque()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        pre_len = len(self.q)
        self.q.append(x)
        for _ in range(pre_len):
            self.q.append(self.q.popleft())


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.popleft()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not len(self.q)  # or just `not self.q`



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# @lc code=end

