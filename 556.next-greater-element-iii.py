#
# @lc app=leetcode id=556 lang=python3
#
# [556] Next Greater Element III
#

# @lc code=start
class Solution:
    # T: O(log(n))
    # S: O(log(n))
    def nextGreaterElement(self, n: int) -> int:
        # digits = list(str(n))
        digits = []
        while n != 0:
            n, digit = divmod(n, 10)
            digits.append(digit)
        digits = digits[::-1]

        nd = len(digits)

        i = nd - 1
        while i >= 1 and digits[i] <= digits[i - 1]:
            i -= 1

        # All digits sorted DESC, impossible
        if i == 0:
            return -1
        
        # Next greater, so find the next smallest digit greater than digits[i - 1],
        # and then swap
        j = i
        while j < nd - 1 and digits[j + 1] > digits[i - 1]:
            j += 1
        digits[i - 1], digits[j] = digits[j], digits[i - 1]
        
        # IMPORTANT: reverse the remaining, because "next greater" (i.e., after swapping above,
        # the digit not greater than digits[i - 1] should be in the front)
        digits[i:] = digits[i:][::-1]

        # ans = int(''.join(digits))
        ans = 0
        for digit in digits:
            ans = ans * 10 + digit

        # Check if result fits in 32-bit int 
        return -1 if ans > (1 << 31) - 1 else ans
        
# @lc code=end

