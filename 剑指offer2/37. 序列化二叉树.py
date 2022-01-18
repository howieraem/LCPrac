from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "[]"
        # BFS approach
        q = deque()
        q.append(root)
        res = []
        while q:
            node = q.popleft()
            if node:
                res.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                res.append('#')
        return '[%s]' % ','.join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data) <= 2:
            return None
        vals = data[1:-1].split(',')
        root = TreeNode(int(vals[0]))
        q = deque()
        q.append(root)
        i = 1
        while q:
            node = q.popleft()
            if vals[i] != '#':
                node.left = TreeNode(int(vals[i]))
                q.append(node.left)
            i += 1
            if vals[i] != '#':
                node.right = TreeNode(int(vals[i]))
                q.append(node.right)
            i += 1
        return root
