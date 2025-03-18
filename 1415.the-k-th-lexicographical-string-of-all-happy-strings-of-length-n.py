#
# @lc app=leetcode id=1415 lang=python3
#
# [1415] The k-th Lexicographical String of All Happy Strings of Length n
#
from collections import deque

# @lc code=start
NEIGHBORS = {
    'a': 'bc',
    'b': 'ac',
    'c': 'ab',
    '': 'abc'
}

class Solution:
    # Solution 1: BFS + graph
    # T: O(n * k)
    # S: O(n * k)
    def getHappyString(self, n: int, k: int) -> str:
        q = deque(['a', 'b', 'c'])

        while len(q[0]) != n:
            u = q.popleft()
            for v in NEIGHBORS[u[-1]]:
                q.append(u + v)
        
        return '' if len(q) < k else q[k - 1]
    
    # Solution 2: graph + math
    # T: O(n)
    # S: O(n)
    def getHappyString(self, n: int, k: int) -> str:
        # For the string of size n, we can build 3 * pow(2, n - 1) strings. 
        # So, if k <= pow(2, n - 1), then the first letter is a; 
        # if k <= 2 * pow(2, n - 1) - then b, otherwise c. 
        # We can also return empty string right away if k > 3 * pow(2, n - 1).
        tot = 3 * (1 << (n - 1))
        if k > tot:
            return ''
        
        k -= 1
        res = ['']
        
        for i in range(n - 1, -1, -1):
            cidx, k = divmod(k, 1 << i)
            res.append(NEIGHBORS[res[-1]][cidx])
        
        return ''.join(res)

# @lc code=end

