#
# @lc app=leetcode id=690 lang=python3
#
# [690] Employee Importance
#
from collections import deque
from typing import *

class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

# @lc code=start
"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    '''
    # BFS
    # T: O(n)
    # S: O(n)
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        id_to_employee = dict()
        for e in employees:
            id_to_employee[e.id] = e
        
        q: Deque['Employee'] = deque()
        q.append(id_to_employee[id])

        ans = 0
        while len(q):
            e = q.popleft()
            ans += e.importance
            for subordinate_id in e.subordinates:
                q.append(id_to_employee[subordinate_id])
        return ans
    '''

    # DFS
    # T: O(n)
    # S: O(n)
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        id_to_employee: Dict[int, 'Employee'] = dict()
        for e in employees:
            id_to_employee[e.id] = e
        
        def dfs(root_id: int) -> int:
            root = id_to_employee[root_id]
            ans = root.importance
            for subordinate_id in root.subordinates:
                ans += dfs(subordinate_id)
            return ans
        
        return dfs(id)

    # Follow-up Q: What if an employee reports to 2 or more bosses and these bosses report to 
    # the same employee with the given id?
    # A: Add a set that tracks which employee ids already visited.


# @lc code=end

