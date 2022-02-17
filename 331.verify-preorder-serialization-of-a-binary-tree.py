#
# @lc app=leetcode id=331 lang=python3
#
# [331] Verify Preorder Serialization of a Binary Tree
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def isValidSerialization(self, preorder: str) -> bool:
        nodes = preorder.split(',')

        # A binary tree is a directed acyclic graph. Thus,
        # in-degrees must equal out-degrees. Nodes except 
        # the root and the leaves have 2 out-degrees and 1
        # in-degree each. Root has 0 in-degree and 2 
        # out-degrees. Leaves have 1 in-degree and 0 
        # out-degree each.
        deg_sum = 0     # positive means out, negative means in
        if nodes[0] != "#":
            # deal with root node
            deg_sum = 2

        for i in range(1, len(nodes)):
            deg_sum -= 1
            if deg_sum < 0:
                return False
            if nodes[i] != '#':
                deg_sum += 2

        return deg_sum == 0

# @lc code=end

