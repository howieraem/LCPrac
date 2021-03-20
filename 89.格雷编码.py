#
# @lc app=leetcode.cn id=89 lang=python3
#
# [89] 格雷编码
#
from typing import List

# @lc code=start
class Solution:
    def grayCode(self, n: int) -> List[int]:
        """Backtrack approach."""
        res = []
        def backtrack(n, x):
            res.append(x)
            for i in range(1, n+1):
                x ^= (1 << (i-1))
                backtrack(i-1, x)
        backtrack(n, 0)
        return res 
    
    def grayCode(self, n: int) -> List[int]:
        """
        Builds gray code for higher `n` from results of lower `n`.
        
        Examples:
            Properties of gray code can be observed below:
            n=0 | n=1   | n=2   | n=3   | ...
            0   | 0     | 00    | 000   | ...
                |       |       | 001   | ...
                |       | 01    | 011   | ...
                |       |       | 010   | ...
                | 1     | 11    | 110   | ...
                |       |       | 111   | ...
                |       | 10    | 101   | ...
                |       |       | 100   | ...

        Notes:
            Result might be different from the above method but still valid.

        """
        res, head = [0], 1
        for i in range(n):
            for j in range(head - 1, -1, -1):   # note: `len(res)` equals `head`
                res.append(head + res[j])   # `head` + mirror of results at previous step
            head <<= 1
        return res
            

# @lc code=end
s = Solution()
print(s.grayCode(1))
