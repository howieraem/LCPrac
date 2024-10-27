#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
#

# @lc code=start
class Solution:
    # T: O(max(len(a), len(b)))
    # S: O(max(len(a), len(b))) in Python (string immutable), or O(1) in C++
    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a), len(b)
        l = (max(i, j) + 1)
        res = ['0'] * l
        carry = 0

        # As we add a and b from their least significant bits, 
        # the result must be updated from the least significant
        # bit to the most significant bit
        while i > 0 and j > 0:
            i -= 1
            j -= 1
            l -= 1
            s = (a[i] == '1') + (b[j] == '1') + carry
            res[l] = str(s & 1)
            carry = (s >> 1)

        while i > 0:
            i -= 1
            l -= 1
            s = (a[i] == '1') + carry
            res[l] = str(s & 1)
            carry = (s >> 1)

        while j > 0:
            j -= 1
            l -= 1
            s = (b[j] == '1') + carry
            res[l] = str(s & 1)
            carry = (s >> 1)

        # Don't forget the last carry
        if carry:
            res[0] = '1'
            return "".join(res)
        return "".join(res[1:])

# @lc code=end

