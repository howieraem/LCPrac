#
# @lc app=leetcode.cn id=133 lang=python3
#
# [133] 克隆图
#

# @lc code=start

# Definition for a Node.

class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        visited = {}    # avoid cloning more than once
        
        def dfs(node):
            if node in visited:
                return visited[node]
            # note: do not initialize with default `[]` argument which 
            # will point to the same list during the whole recursion
            cloned = Node(node.val, [])     
            visited[node] = cloned
            for nb in node.neighbors:
                cloned.neighbors.append(dfs(nb))
            return cloned

        return dfs(node)
        
# @lc code=end
n1 = Node(1)
n2 = Node(2)
n3 = Node(3)
n4 = Node(4)
n1.neighbors = [n2, n4]
n2.neighbors = [n3, n1]
n3.neighbors = [n4, n2]
n4.neighbors = [n1, n3]

n = Solution().cloneGraph(n1)
print(n.neighbors)
