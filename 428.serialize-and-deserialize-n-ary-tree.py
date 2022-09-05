#
# @lc app=leetcode id=428 lang=python3
#
# [428] Serialize and Deserialize N-ary Tree
#
from collections import deque
from typing import *

class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children: List[Optional[Node]] = children

# @lc code=start
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Codec:
    # T: O(n), n := the number of nodes
    # S: O(n)
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        serial = []
        
        def preorder(node: 'Node'):
            if node:
                serial.append(str(node.val))
                for c in node.children:
                    preorder(c)
                serial.append('#')
        
        preorder(root)
        return " ".join(serial)
	
    # T: O(n), n := len(data)
    # S: O(n)
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        q = deque(data.split())

        def helper():
            if not len(q):
                return None
            node = Node(int(q.popleft()), [])
            while q[0] != '#':
                node.children.append(helper())
            q.popleft()  # remove the '#'
            return node

        return helper()

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
# @lc code=end

