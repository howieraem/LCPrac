#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        """Solution with BFS."""
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
                res.append(level)
        return res


# @lc code=end

