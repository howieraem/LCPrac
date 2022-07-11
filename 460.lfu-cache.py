#
# @lc app=leetcode id=460 lang=python3
#
# [460] LFU Cache
#
from collections import defaultdict
from typing import DefaultDict, Dict

# @lc code=start
class DLinkedList:
    class Node:
        def __init__(self, k, v):
            self.k = k
            self.v = v
            self.freq = 1
            self.prev: DLinkedList.Node = None
            self.next: DLinkedList.Node = None

    def __init__(self):
        self._head = DLinkedList.Node(None, None)
        self._head.prev = self._head.next = self._head
        self._sz = 0

    def __len__(self):
        return self._sz

    def add_to_head(self, node):
        if isinstance(node, DLinkedList.Node):
            node.next = self._head.next
            node.prev = self._head
            node.next.prev = node
            self._head.next = node
            self._sz += 1

    def remove_node(self, node=None):
        if not self._sz:
            return None
        if not node:
            node = self._head.prev
        if isinstance(node, DLinkedList.Node):
            node.prev.next = node.next
            node.next.prev = node.prev
            self._sz -= 1
            return node
        return None


class LFUCache:
    def __init__(self, capacity: int):
        self._sz = 0
        self._cap = capacity
        self._nodes: Dict[int, DLinkedList.Node] = dict()
        self._freqs: DefaultDict[int, DLinkedList] = defaultdict(DLinkedList)
        self._min_freq = 0

    def _update(self, node: DLinkedList.Node):
        self._freqs[node.freq].remove_node(node)
        if self._min_freq == node.freq and not len(self._freqs[node.freq]):
            self._min_freq += 1
        node.freq += 1
        self._freqs[node.freq].add_to_head(node)

    # T: O(1)
    def get(self, key: int) -> int:
        if key not in self._nodes:
            return -1
        node = self._nodes[key]
        self._update(node)
        return node.v

    # T: O(1)
    def put(self, key: int, value: int) -> None:
        if not self._cap:
            return
        if key in self._nodes:
            node = self._nodes[key]
            self._update(node)
            node.v = value
        else:
            if self._sz == self._cap:
                # Full, pop the least freq element
                node = self._freqs[self._min_freq].remove_node()
                self._nodes.pop(node.k)
                self._sz -= 1
            node = DLinkedList.Node(key, value)
            self._nodes[key] = node
            self._freqs[1].add_to_head(node)
            self._min_freq = 1
            self._sz += 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

