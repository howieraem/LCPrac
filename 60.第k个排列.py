#
# @lc app=leetcode.cn id=60 lang=python3
#
# [60] 第k个排列
#
import math
from typing import List

# @lc code=start
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        """找规律

        Examples:
            Suppose n = 4, then permutations are
            {1 + permutations([2, 3, 4])} U {2 + permutations([1, 3, 4])} U \
                {3 + permutations([1, 2, 4])} U {4 + permutations([1, 2, 3])}
            there are (n-1)! permutations for each subset. Thus, we can quickly
            find out which subset the kth permutation is in. Continue this
            process until n reduces to 0.

        """        
        tokens = [str(i) for i in range(1, n+1)]
        res = ''
        k -= 1  # make it zero-indexed
        while n > 0:
            n -= 1
            a, k = divmod(k, math.factorial(n))
            res += tokens.pop(a)
        return res

    """
    Original solution, keeps finding the next permutation, but too slow:
    def getPermutation(self, n: int, k: int) -> str:
        f = math.factorial(n)
        if k != f:
            # avoid repetitions
            k %= f
        nums = list(range(1, n+1))
        for _ in range(2, k+1):
            self.nextPermutationInplace(nums)
        return ''.join(str(n) for n in nums)


    def nextPermutationInplace(self, nums: List[int]) -> None:
        n = len(nums)
        if n < 2:
            return
        idx1 = 0
        for i in range(n-1, 0, -1):
            if nums[i] > nums[i-1]:
                idx1 = i
                break
        if idx1 == n-1:
            nums[idx1], nums[idx1-1] = nums[idx1-1], nums[idx1]
        else:
            # ensure the next permutation, not just a greater one
            mid = (idx1+n) >> 1
            for k, j in enumerate(range(idx1, mid)):
                nums[j], nums[n-k-1] = nums[n-k-1], nums[j]
            if not idx1:
                return
            for idx2 in range(idx1, n):
                if nums[idx2] > nums[idx1-1]:
                    nums[idx1-1], nums[idx2] = nums[idx2], nums[idx1-1]
                    break
    """

# @lc code=end
s = Solution()
print(s.getPermutation(3, 6))
