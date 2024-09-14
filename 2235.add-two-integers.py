class Solution:
    # T: O(log(y))
    # S: O(1)
    def sum(self, x: int, y: int) -> int:
        """
        # In Python, below only works if both x and y are non-negative
        while y != 0:
            carry = x & y
            x ^= y
            y = carry << 1
        return x
        """
        MAX = 0x7FFFFFFF
        mask = 0xFFFFFFFF
        while y != 0:
            x, y = (x ^ y) & mask, ((x & y) << 1) & mask
        return x if x <= MAX else ~(x ^ mask)
