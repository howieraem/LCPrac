#
# @lc app=leetcode.cn id=146 lang=python3
#
# [146] LRU缓存机制
#

# @lc code=start
class DListNode:
    """Implements node in a doubly linked list."""
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.prev = None
        self.next = None    

class LRUCache:        
    def __init__(self, capacity: int):
        self.__cap = capacity
        self.__head = DListNode(None, None)  # most recent
        self.__tail = DListNode(None, None)  # dummy node following the least recent
        self.__head.next = self.__tail
        self.__tail.prev = self.__head
        self.__data = dict()

    def get(self, key: int) -> int:
        node = self.__data.get(key)
        if node is None:
            return -1
        res = node.val
        self.__rmNode(node)
        self.__appendHead(node)
        return res

    def put(self, key: int, value: int) -> None:
        node = self.__data.get(key)
        if node is not None:
            node.val = value
            self.__rmNode(node)
            self.__appendHead(node)
        else:
            if len(self.__data) >= self.__cap:
                node = self.__tail.prev     # note here
                self.__data.pop(node.key)   # or `del self.__data[node.key]`
                self.__rmNode(node)
            node = DListNode(key, value)
            self.__appendHead(node)
            self.__data[key] = node

    # Doubly linked list utils    
    def __appendHead(self, node):
        node.next, node.prev = self.__head.next, self.__head
        temp = self.__head.next
        self.__head.next = node
        temp.prev = node

    def __rmNode(self, node):
        node.prev.next, node.next.prev = node.next, node.prev


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end
# c = LRUCache(2)
# c.put(1, 1)
# c.put(2, 2)
# print(c.get(1))
# c.put(3, 3)
# print(c.get(2))
# c.put(4, 4)
# print(c.get(1))
# print(c.get(3))
# print(c.get(4))
