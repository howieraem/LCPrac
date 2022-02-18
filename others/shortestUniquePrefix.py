# Question: https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
# 
# Given an array of words, find all shortest unique prefixes to represent 
# each word in the given array. Assume that no word is prefix of another. 
# 
# Examples: 
#
# Input: ["zebra", "dog", "duck", "dove"]
# Output: ["dog", "dov", "du", "z"]
# Explanation: dog => dog
#              dove => dov 
#              duck => du
#              zebra => z
#
# Input: ["geeksgeeks", "geeksquiz", "geeksforgeeks"]
# Output: ["geeksf", "geeksg", "geeksq"]
from collections import OrderedDict
from typing import List


class Node:
    def __init__(self) -> None:
        # Use OrderedDict because the iteration order 
        # is the same as the insertion order.
        # Java equivalent: LinkedHashMap.
        self.children: OrderedDict = OrderedDict()
        
        self.freq = 0


def insert(root: Node, w: str):
    cur = root
    for c in w:
        if c not in cur.children:
            cur.children[c] = Node()
        cur.children[c].freq += 1
        cur = cur.children[c]


def dfs(root: Node, path: str, res: list):
    if root is None:
        return
    if root.freq == 1:
        res.append(path)
        return
    
    for c, child in root.children.items():
        dfs(child, path + c, res)


def shortest_uniq_prefix(words: List[str]) -> List[str]:
    root = Node()
    for w in words:
        insert(root, w)

    res = []
    dfs(root, "", res)
    return res


def main():
    words = ["zebra", "zee", "zea", "dove", "dogs", "duck"]
    print(shortest_uniq_prefix(words))


if __name__ == '__main__':
    main()
