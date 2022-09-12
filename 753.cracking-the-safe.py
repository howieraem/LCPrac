#
# @lc app=leetcode id=753 lang=python3
#
# [753] Cracking the Safe
#
from typing import *

# @lc code=start
class Solution:
    # A de Bruijn sequence of order n on a size-k alphabet A is a cyclic sequence 
    # in which every possible length-n string on A occurs exactly once as a substring. 
    # It has length k^n, which is also the number of distinct substrings of length n 
    # on a size-k alphabet; de Bruijn sequences are therefore optimally short.
    # T: O(k ^ (2n)) worst case, a node can backtrack from visiting almost all k^n nodes, and there are k^n such nodes.
    # S: O(k ^ n)
    def crackSafe(self, n: int, k: int) -> str:
        total = pow(k, n)
        res = ['0'] * n
        vis = set()
        vis.add("".join(res))

        def backtrack(res: List[str], vis: Set[str]) -> bool:
            if len(vis) == total:
                return True
            for i in range(k):
                res.append(str(i))
                last_n_digits = res[-n:]
                last_n_digits_str = "".join(last_n_digits)
                if last_n_digits_str not in vis:
                    vis.add(last_n_digits_str)
                    if backtrack(res, vis):
                        return True
                    vis.remove(last_n_digits_str)
                res.pop()
            return False
        
        backtrack(res, vis)
        return "".join(res)


# @lc code=end

