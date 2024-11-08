#
# @lc app=leetcode id=337 lang=python3
#
# [337] House Robber III
#
from typing import *

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
    # DP at node + Post-order traversal DFS
    # T: O(n)
    # S: O(n)
    def rob(self, root: Optional[TreeNode]) -> int:
        return max(self.helper(root))

    @staticmethod
    def helper(node: TreeNode) -> Tuple[int, int]:
        if node is None:
            return 0, 0
        
        l_rob_ret, l_no_rob_ret = Solution.helper(node.left)
        r_rob_ret, r_no_rob_ret = Solution.helper(node.right)
        
        # Rob at the current node, need to use the no rob results from direct children
        rob_ret = node.val + l_no_rob_ret + r_no_rob_ret

        # Node that between any 2 robbed houses on a path from root to leaf, 
        # the number of houses not robbed can be greater than 1
        no_rob_ret = max(l_rob_ret, l_no_rob_ret) + max(r_rob_ret, r_no_rob_ret)
        
        return rob_ret, no_rob_ret
    
    '''
    # follow-up: n-ary tree
    def helper(node):
        if node is None:
            return 0, 0
        dp_rob_current = node.val
        dp_rob_skip = 0
        for child in node.children:
            dp_child_rob, dp_child_skip = helper(child)
            dp_rob_current += dp_child_skip
            dp_rob_skip += max(dp_child_rob, dp_child_skip)
        return dp_rob_current, dp_rob_skip
    '''

# @lc code=end

