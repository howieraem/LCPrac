from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def preorder(node: TreeNode):
    res = []
    p = node
    stack: List[TreeNode] = []
    while len(stack) or p:
        if p:
            res.append(p.val)
            stack.append(p)
            p = p.left
        else:
            p = stack[-1]
            stack.pop()
            p = p.right
    return res


def inorder(node: TreeNode):
    res = []
    p = node
    stack: List[TreeNode] = []
    while len(stack) or p:
        if p:
            stack.append(p)
            p = p.left
        else:
            p = stack[-1]
            stack.pop()
            res.append(p.val)
            p = p.right
    return res


def postorder(node: TreeNode):
    res = []
    p = node
    pre_vis = None
    stack: List[TreeNode] = []

    while p:
        stack.append(p)
        p = p.left

    while len(stack):
        p = stack[-1]
        stack.pop()
        if not p.right or p.right == pre_vis:
            res.append(p.val)
            pre_vis = p
        else:
            stack.append(p)
            p = p.right
            while p:
                stack.append(p)
                p = p.left
    return res
