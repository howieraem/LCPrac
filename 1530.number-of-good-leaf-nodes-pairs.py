from typing import List
#
# @lc app=leetcode id=1530 lang=python3
#
# [1530] Number of Good Leaf Nodes Pairs
#
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # T: O(n ^ 2), n := no. of nodes
    # S: O(n) worst depth
    def countPairs(self, root: TreeNode, distance: int) -> int:
        ans = 0

        def dfs(node: TreeNode) -> List[int]:
            if not node:
                return []
            if not node.left and not node.right:
                return [1]    
            nonlocal ans

            # post-order traversal
            left = dfs(node.left)
            right = dfs(node.right)
            ans += sum(l + r <= distance for l in left for r in right)
            dists = []
            for d in left + right:
                nd = d + 1
                if nd < distance:
                    dists.append(nd)
            return dists

        dfs(root)
        return ans


# @lc code=end

