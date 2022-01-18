#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    PRIME_MAP = {
        'a': 2, 'b': 3, 'c': 5, 'd': 7, 'e': 11, 'f': 13, 'g': 17, 
        'h': 19, 'i': 23, 'j': 29, 'k': 31, 'l': 37, 'm': 41, 'n': 43, 
        'o': 47, 'p': 53, 'q': 59, 'r': 61, 's': 67, 't': 71, 'u': 73, 
        'v': 79, 'w': 83, 'x': 89, 'y': 97, 'z': 101
    }

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        visited = defaultdict(list)
        for s in strs:
            # Let N be string length.

            # Below is O(NlogN)
            # ss = ''.join(sorted(s))
            # visited[ss].append(s)

            # Below is O(N), but be careful of overflow in other programming languages
            key = 1
            for c in s:
                # Use primes to ensure uniqueness of string encoding
                key *= self.PRIME_MAP[c]
            visited[key].append(s)
        return list(visited.values())

# @lc code=end
# s = Solution()
# print(s.groupAnagrams(['eat', 'tea', 'tan', 'ate', 'nat', 'bat']))
