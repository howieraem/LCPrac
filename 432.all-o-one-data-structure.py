#
# @lc app=leetcode id=432 lang=python3
#
# [432] All O`one Data Structure
#
from __future__ import annotations
from typing import Set, Dict

# @lc code=start
class Bucket:
    def __init__(self, cnt):
        self.cnt: int = cnt
        self.keys: Set = set()
        self.prev: Bucket = None
        self.next: Bucket = None

    def append_bucket(self, other):
        other.prev = self
        other.next = self.next
        self.next.prev = other
        self.next = other


class AllOne:
    def __init__(self):
        self.head = Bucket(float('-inf'))
        self.tail = Bucket(float('inf'))
        self.head.next = self.tail
        self.tail.prev = self.head
        self.key_to_bucket: Dict[str, Bucket] = dict()

    @staticmethod
    def __remove_bucket(bucket: Bucket):
        bucket.next.prev = bucket.prev
        bucket.prev.next = bucket.next

    @staticmethod
    def __remove_key_from_bucket(bucket: Bucket, k: str):
        bucket.keys.discard(k)
        if not len(bucket.keys):
            AllOne.__remove_bucket(bucket)

    def inc(self, key: str) -> None:
        if key in self.key_to_bucket:
            bucket = self.key_to_bucket[key]
            if bucket.cnt == bucket.next.cnt - 1:
                # Buckets' counts contiguous
                self.key_to_bucket[key] = bucket.next
                bucket.next.keys.add(key)
            else:
                # Buckets' counts not contiguous (diff > 1)
                new_bucket = Bucket(bucket.cnt + 1)
                new_bucket.keys.add(key)
                self.key_to_bucket[key] = new_bucket
                bucket.append_bucket(new_bucket)
            self.__remove_key_from_bucket(bucket, key)
        else:
            bucket = self.head.next
            if bucket.cnt != 1:
                bucket = Bucket(1)
                self.head.append_bucket(bucket)
            bucket.keys.add(key)
            self.key_to_bucket[key] = bucket

    def dec(self, key: str) -> None:
        if key not in self.key_to_bucket:
            return
        bucket = self.key_to_bucket[key]
        if bucket.cnt == 1:
            self.key_to_bucket.pop(key)
        elif bucket.cnt == bucket.prev.cnt + 1:
            # Buckets' counts contiguous
            bucket.prev.keys.add(key)
            self.key_to_bucket[key] = bucket.prev
        else:
            # Buckets' counts not contiguous (diff > 1)
            new_bucket = Bucket(bucket.cnt - 1)
            new_bucket.keys.add(key)
            bucket.prev.append_bucket(new_bucket)
        self.__remove_key_from_bucket(bucket, key)

    def getMaxKey(self) -> str:
        return next(iter(self.tail.prev.keys)) if self.tail.prev != self.head else ""

    def getMinKey(self) -> str:
        return next(iter(self.head.next.keys)) if self.head.next != self.tail else ""


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
# @lc code=end

