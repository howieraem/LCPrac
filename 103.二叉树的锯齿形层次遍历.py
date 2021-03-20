#
# @lc app=leetcode.cn id=103 lang=python3
#
# [103] 二叉树的锯齿形层次遍历
#
from typing import List

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        queue, res = [root], []
        rev = False
        while queue:
            lvl = []
            for _ in range(len(queue)):
                # dequeue
                cur = queue.pop(0)

                # node is null
                if not cur:
                    continue
                
                # visit the current node
                if rev:     # reverse the order of appending
                    lvl.insert(0, cur.val)
                else:
                    lvl.append(cur.val)

                # enqueue the children
                queue.append(cur.left)
                queue.append(cur.right)
            rev = not rev
            if lvl:
                res.append(lvl)
        return res

# @lc code=end
'''
n1 = TreeNode(3)
n2 = TreeNode(9)
n3 = TreeNode(20)
n4 = TreeNode(15)
n5 = TreeNode(7)
n1.left, n1.right = n2, n3
n3.left, n3.right = n4, n5
'''
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n5 = TreeNode(5)
n1.left, n1.right = n2, n3
n2.left, n2.right = n4, n5

s = Solution()
print(s.zigzagLevelOrder(n1))
