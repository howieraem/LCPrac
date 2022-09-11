#
# @lc app=leetcode id=1506 lang=python3
#
# [1506] Find Root of N-Ary Tree
#
from typing import *

class Node:
    def __init__(self, val=None, children=None):
        self.val: int = val
        self.children: Optional[List[Optional[Node]]] = children if children is not None else []

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    # T: O(n)
    # S: O(1)
    def findRoot(self, tree: List['Node']) -> 'Node':
        if not len(tree):
            return None

        # Idea: each node except root will be visited twice,
        # one as child and one as subtree root/parent. Thus, 
        # use XOR to find the root node value, as bits of all
        # other node values will become 0 after two visits
        mask = 0
        for node in tree:
            mask ^= node.val

            for child in node.children:
                mask ^= child.val

        # Now mask should equal to the root val
        for node in tree:
            if node.val == mask:
                return node
        return None

# @lc code=end

