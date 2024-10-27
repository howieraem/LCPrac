#
# @lc app=leetcode id=460 lang=python3
#
# [460] LFU Cache
#
from collections import defaultdict
from typing import DefaultDict, Dict, Optional

# @lc code=start
class DLinkedList:
    class Node:
        def __init__(self, k, v) -> None:
            self.k = k
            self.v = v
            self.freq = 1   # required in LFU but not in LRU
            self.prev: Optional[DLinkedList.Node] = None
            self.next: Optional[DLinkedList.Node] = None

    def __init__(self) -> None:
        self._head = DLinkedList.Node(None, None)
        # circular, easier to track the tail
        self._head.prev = self._head.next = self._head
        self._sz: int = 0

    def __len__(self) -> int:
        return self._sz

    def add_to_head(self, node):
        if isinstance(node, DLinkedList.Node):
            node.next = self._head.next
            node.prev = self._head
            node.next.prev = node
            self._head.next = node
            self._sz += 1

    def remove_node(self, node=None):
        if self._sz == 0:
            return None
        if node is None:
            node = self._head.prev  # remove tail of list by default
        if isinstance(node, DLinkedList.Node):
            node.prev.next = node.next
            node.next.prev = node.prev
            self._sz -= 1
            return node
        return None


class LFUCache:
    # Different from LRU: 
    # - pop based on op frequency, not just most recent op
    # - each frequency corresponds to a doubly linked list
    def __init__(self, capacity: int) -> None:
        self._sz = 0
        self._cap = capacity
        self._nodes: Dict[int, DLinkedList.Node] = dict()  # k: node key, v: node
        self._freqs: DefaultDict[int, DLinkedList] = defaultdict(DLinkedList)  # k: freq, v: doubly linked list
        self._min_freq = 0

    def _update(self, node: DLinkedList.Node) -> None:
        self._freqs[node.freq].remove_node(node)
        if self._min_freq == node.freq and len(self._freqs[node.freq]) == 0:
            self._min_freq += 1
        node.freq += 1
        self._freqs[node.freq].add_to_head(node)

    # T: O(1)
    def get(self, key: int) -> int:
        node = self._nodes.get(key, None)
        if node is None:
            return -1
        self._update(node)
        return node.v

    # T: O(1)
    def put(self, key: int, value: int) -> None:
        if self._cap == 0:
            return
        if key in self._nodes:
            node = self._nodes[key]
            self._update(node)
            node.v = value
        else:
            if self._sz == self._cap:
                # Full, pop the least freq element which is the tail of 
                # the list with the minimum freq
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

