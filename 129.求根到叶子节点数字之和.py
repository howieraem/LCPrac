#
# @lc app=leetcode.cn id=129 lang=python3
#
# [129] 求根到叶子节点数字之和
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:

        def dfs(root, res):
            if not root:
                return 0
            res = res*10 + root.val
            if not root.left and not root.right:
                return res
            return dfs(root.left, res)+dfs(root.right, res)
        
        return dfs(root, 0)
        

# @lc code=end
t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(5)
t5 = TreeNode(1)
t1.left, t1.right = t2, t3
# t2.left, t2.right = t4, t5
print(Solution().sumNumbers(t1))
