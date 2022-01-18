#
# @lc app=leetcode.cn id=652 lang=python3
#
# [652] 寻找重复的子树
#
from collections import defaultdict

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    __slots__ = ['subtree_cnts', 'res']

    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        self.subtree_cnts = defaultdict(int)
        self.res = []
        self.__traverse(root)
        return self.res

    def __traverse(self, root):
        # post-order traversal to serialize subtrees for counting duplicates
        if not root:
            return '#'
        left = self.__traverse(root.left)
        right = self.__traverse(root.right)
        subtree_serialized = left + ',' + right + ',' + str(root.val)
        cnt = self.subtree_cnts[subtree_serialized]
        if cnt == 1:
            self.res.append(root)
        self.subtree_cnts[subtree_serialized] = cnt + 1
        return subtree_serialized

# @lc code=end
