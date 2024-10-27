#
# @lc app=leetcode id=988 lang=python3
#
# [988] Smallest String Starting From Leaf
#
from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: Optional[TreeNode] = left
        self.right: Optional[TreeNode] = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # DFS pre-order traversal
    # T: O(n ^ 2), n := no. of nodes
    # S: O(n ^ 2)
    # Note: if str_x < str_y, then str_x + str_a < str_y + str_a is NOT always true.
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        OFFSET = ord('a')
        ans = ""

        def dfs(node: Optional[TreeNode], cur_str: str) -> None:
            if node is None:
                return 
            
            # O(n), but can't be optimized because it's bottom to top
            cur_str = chr(node.val + OFFSET) + cur_str

            if node.left is None and node.right is None:
                # leaf node
                nonlocal ans
                if len(ans) == 0:
                    # init
                    ans = cur_str
                else:
                    ans = min(ans, cur_str)

            dfs(node.left, cur_str)
            dfs(node.right, cur_str)

        dfs(root, "")
        return ans


# @lc code=end

