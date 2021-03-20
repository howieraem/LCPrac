#
# @lc app=leetcode.cn id=107 lang=python3
#
# [107] 二叉树的层次遍历 II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        """Reusing code from question [102]."""
        queue, res = [root], []
        while queue:
            level = []
            for _ in range(len(queue)):
                # dequeue
                cur = queue.pop(0)

                # node is null
                if not cur:
                    continue
                
                # visit the current node
                level.append(cur.val)

                # enqueue the children
                queue.append(cur.left)
                queue.append(cur.right)
            if level:
                # if not reversing `res` later, one can
                # do `insert(0, level)` here.
                res.append(level)
        res.reverse()   # or `return res[::-1]`
        return res

# @lc code=end

