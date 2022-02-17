#
# @lc app=leetcode id=1650 lang=python3
#
# [1650] Lowest Common Ancestor of a Binary Tree III
#
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    # Same as finding the intersection of 2 linked lists (a linked list
    # is a special case of binary tree)
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        p_cur, q_cur = p, q

        while p_cur != q_cur:
            p_cur = p_cur.parent if p_cur else q
            q_cur = q_cur.parent if q_cur else p

        return p_cur

# @lc code=end

