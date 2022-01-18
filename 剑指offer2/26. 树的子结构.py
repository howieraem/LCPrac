# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not (A and B):
            return False
        return (self.hasSubStruct(A, B) or
                self.isSubStructure(A.left, B) or
                self.isSubStructure(A.right, B)) 
    
    @staticmethod
    def hasSubStruct(A, B):
        """Returns whether A has substructure B."""
        if not B:
            # A None, B None -> True
            # A not None, B None -> True
            return True
        if not A or A.val != B.val:
            # A None, B not None -> False
            return False
        return (Solution.hasSubStruct(A.left, B.left) and 
                Solution.hasSubStruct(A.right, B.right))
