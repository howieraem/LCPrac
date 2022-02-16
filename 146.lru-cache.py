#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
#

# @lc code=start
class Node:
    def __init__(self, k=0, v=0) -> None:
        self.pre: Node = None
        self.nxt: Node = None
        self.k = k
        self.v = v

class LRUCache:
    def __init__(self, capacity: int):
        self.head = Node()
        self.tail = Node()
        self.head.nxt = self.tail
        self.tail.pre = self.head
        self.cap = capacity
        self.d = dict() # key: int, val: Node

    def get(self, key: int) -> int:
        if key not in self.d:
            return -1
        node: Node = self.d[key]
        self._move_to_head(node)
        return node.v

    def put(self, key: int, value: int) -> None:
        if key in self.d:
            self.d[key].v = value
            self._move_to_head(self.d[key])
        else:
            if len(self.d) == self.cap:
                last = self._pop_tail()
                del self.d[last.k]
            node = Node(key, value)
            self.d[key] = node
            self._add_to_head(node)
        
    def _add_to_head(self, node: Node):
        node.nxt = self.head.nxt
        self.head.nxt.pre = node
        self.head.nxt = node
        node.pre = self.head

    def _remove_node(self, node: Node):
        node.nxt.pre = node.pre
        node.pre.nxt = node.nxt

    def _pop_tail(self) -> Node:
        node = self.tail.pre
        self._remove_node(node)
        return node

    def _move_to_head(self, node: Node):
        self._remove_node(node)
        self._add_to_head(node)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

