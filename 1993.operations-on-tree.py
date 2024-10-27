#
# @lc app=leetcode id=1993 lang=python3
#
# [1993] Operations on Tree
#
from typing import *

# @lc code=start
# hash map + graph + DFS
class LockingTree:
    # T: O(n)
    def __init__(self, parent: List[int]):
        self.parent = parent              # node -> parent
        self.tree = [[] for _ in parent]  # node -> children
        for i, x in enumerate(parent):
            if x != -1:
                self.tree[x].append(i)
        self.locks = dict()  # k: node num, v: user

    # T: O(1)
    def lock(self, num: int, user: int) -> bool:
        if num in self.locks:
            return False
        self.locks[num] = user
        return True

    # T: O(1)
    def unlock(self, num: int, user: int) -> bool:
        if self.locks.get(num) != user:
            return False
        self.locks.pop(num)
        return True      

    # T: O(n)
    def upgrade(self, num: int, user: int) -> bool:
        if num in self.locks:
            return False

        # Iterative DFS
        # Check if any ancestor locked
        node = num
        while node != -1:
            if node in self.locks:
                return False
            node = self.parent[node]
        
        # Iterative DFS
        # Unlock descendants
        st = [num]
        n_locked_descendants = 0
        while len(st) > 0:
            node = st.pop()
            if node in self.locks:
                n_locked_descendants += 1
                self.locks.pop(node)
            
            for child in self.tree[node]:
                st.append(child)

        if n_locked_descendants > 0:
            self.locks[num] = user
            return True

        return False   # no descendant locked


# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)
# @lc code=end

