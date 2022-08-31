#
# @lc app=leetcode id=1948 lang=python3
#
# [1948] Delete Duplicate Folders in System
#
from collections import defaultdict
from typing import List

# @lc code=start
class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.is_deleted = False

class Solution:
    # T: O(n * l * log(n * l)), n := len(paths), l := avg length of each path
    # S: O(n * l)
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = TrieNode()
        paths.sort()  # IMPORTANT

        # Add all paths to trie
        for path in paths:
            node = root
            for s in path:
                node = node.children[s]

        serialized_nodes = defaultdict(list)

        def traverse_and_serialize(node: TrieNode):
            key = "(" + "".join(s + traverse_and_serialize(node.children[s]) for s in node.children) + ")"
            if key != "()":
                serialized_nodes[key].append(node)
            return key

        traverse_and_serialize(root)

        # Mark deletion
        for nodes in serialized_nodes.values():
            if len(nodes) > 1:
                for node in nodes:
                    node.is_deleted = True

        res = []

        def construct_deleted_paths(node: TrieNode, path: list):
            for s in node.children:
                child = node.children[s]
                if not child.is_deleted:
                    construct_deleted_paths(child, path + [s])
            if len(path):
                res.append(path[:])

        construct_deleted_paths(root, [])
        return res

# @lc code=end

