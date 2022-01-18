class Solution:
    target = 1  # 要找的数字

    def countDigitOne(self, n: int) -> int:
        ans, base = 0, 1
        while base <= n:
            cur = (n // base) % 10      # 从个位开始，到十位、百位、千位...
            high = n // (base * 10)     # 当前位前的所有数字
            low = n - n // base * base  # 当前位后的所有数字

            if cur > self.target:
                ans += (high + 1) * base
            elif cur == self.target:
                ans += high * base + low + 1
            else:
                ans += high * base
            
            base *= 10
        return ans
