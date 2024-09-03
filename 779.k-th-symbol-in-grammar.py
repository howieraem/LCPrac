#
# @lc app=leetcode id=779 lang=python3
#
# [779] K-th Symbol in Grammar
#

# @lc code=start
class Solution:
    '''
    Find the pattern:
    #1                  0
    #2        0                   1
    #3   0         1         1         0
    #4 0   1     1   0     1   0     0   1
    '''

    # Iterative solution
    # T: O(n)
    # S: O(1)
    def kthGrammar(self, n: int, k: int) -> int:
        n_digits = 1 << (n - 1)   # no. of digits on nth row

        first_digit_of_row_flag = True

        while n_digits != 1:
            n_digits >>= 1
            if k > n_digits:
                # k is in second half of the row, 
                # convert to the first half and 
                # flip the digit
                k -= n_digits
                first_digit_of_row_flag = not first_digit_of_row_flag
        
        return 0 if first_digit_of_row_flag else 1

    '''
    # Recursive solution
    # T: O(n)
    # S: O(n)
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        if k & 1:  # k is odd
            return self.kthGrammar(n - 1, (k + 1) >> 1)
        else:
            return 1 if self.kthGrammar(n - 1, k >> 1) == 0 else 0
    '''

# @lc code=end

