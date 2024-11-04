#
# @lc app=leetcode id=172 lang=python3
#
# [172] Factorial Trailing Zeroes
#

# @lc code=start
class Solution:
    # T: O(log(n))
    # S: O(log(n)) if recursive, O(1) if iterative
    def trailingZeroes(self, n: int) -> int:
        '''
        The idea is:

        - The ZERO comes from 10.
        - The 10 comes from 2 x 5
        - We need to account for all the products of 5 and 2. likes 4×5 = 20 ...
        - If we take all the numbers with 5 as a factor, we'll have way more than enough 
          even numbers to pair with them to get factors of 10
        '''
        # Recursive
        # return 0 if n == 0 else n / 5 + self.trailingZeroes(n / 5)

        # Iterative
        ans = 0
        while n > 0:
            n //= 5
            ans += n
        return ans

# @lc code=end

