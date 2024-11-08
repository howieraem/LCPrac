#
# @lc app=leetcode id=60 lang=python3
#
# [60] Permutation Sequence
#
import math

# @lc code=start
from sortedcontainers import SortedList


class Solution:
    # Math + pattern
    # T: O(n * sqrt(n) * (log(n)) ^ 2) for sorted list and math.factorial 
    # S: O(n)
    def getPermutation(self, n: int, k: int) -> str:
        digits = SortedList() 
        for i in range(1, n + 1):
            # '1', '2', ..., 'n'
            digits.add(str(i))
        k -= 1

        res = []

        # Explanation:
        # Suppose n = 4, then permutations are
        # {1 + permutations([2, 3, 4])} U {2 + permutations([1, 3, 4])} U \
        #     {3 + permutations([1, 2, 4])} U {4 + permutations([1, 2, 3])}
        # there are (n - 1)! permutations for each subset. Thus, we can quickly
        # find out which subset the kth permutation is in. Continue this
        # process until n reduces to 0.
        while n > 0:
            next_num_permutations = math.factorial(n - 1)
            i, k = divmod(k, next_num_permutations)
            res.append(digits.pop(i))   # O(log(n)), better than normal array O(n)
            n -= 1
        
        return ''.join(res)


# @lc code=end

