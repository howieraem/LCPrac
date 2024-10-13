from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # T: O(n * log(n)), n := the number of nodes
    # S: O(n)
    def kthLargestPerfectSubtree(self, root: Optional[TreeNode], k: int) -> int:
        sizes = []

        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            nonlocal sizes
            if node.left is None and node.right is None:
                sizes.append(1)
                return 1

            l = dfs(node.left)
            r = dfs(node.right)

            if l == r >= 0:
                size = l + r + 1
                sizes.append(size)
                return size
            
            return -1  # not a perfect binary tree

        dfs(root)

        if len(sizes) < k:
            return -1

        sizes.sort(reverse=True)
        return sizes[k - 1]
