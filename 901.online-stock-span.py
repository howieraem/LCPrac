#
# @lc app=leetcode id=901 lang=python3
#
# [901] Online Stock Span
#

# @lc code=start
# Mono-stack
# S: O(n)?
class StockSpanner:
    # T: O(1)
    def __init__(self):
        self.st = []  # (price, price_span) ordered DESC
    
    # T: Amortised O(1)
    def next(self, price: int) -> int:
        span = 1
        while len(self.st) > 0 and self.st[-1][0] <= price:  # less than or equal by definition
            span += self.st.pop()[1]
        self.st.append((price, span))
        return span

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# @lc code=end

