#
# @lc app=leetcode id=1087 lang=python3
#
# [1087] Brace Expansion
#
from typing import *

# @lc code=start
class Solution:
    # Backtracking, recursive
    # T: O(n * 3 ^ N)
    # S: O(n * 3 ^ N)
    def expand(self, s: str) -> List[str]:
        res = []

        def backtrack(path: List[str], idx: int) -> None:
            if idx == len(s):
                res.append(''.join(path))
                return
            
            if s[idx] == '{':
                j = idx + 1
                while s[j] != '}':
                    j += 1
                
                # sort letters in {} to ensure order
                for letter in sorted(s[idx + 1:j].split(',')):
                    path.append(letter)
                    backtrack(path, j + 1)
                    path.pop()
            else:
                path.append(s[idx])
                backtrack(path, idx + 1)
                path.pop()
        
        path = []
        backtrack(path, 0)
        return res
    
    # Iterative
    # T: O(n * 3 ^ N)
    # S: O(n * 3 ^ N)
    def expand(self, s: str) -> List[str]:
        output = ['']
        chars = []
        inner = False 
        
        for c in s:
            if c == ',':
                continue
            elif c == '{':
                inner = True 
            elif c == '}':
                output = [base + char for base in output for char in sorted(chars)]
                chars = []
                inner = False 
            elif inner:
                chars.append(c)
            else:
                # not inner chars
                output = [base + c for base in output]
                
        return output

# @lc code=end

