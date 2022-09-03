#
# @lc app=leetcode id=1352 lang=python3
#
# [1352] Product of the Last K Numbers
#

# @lc code=start
class ProductOfNumbers:

    def __init__(self):
        self.prefix_product = [1]

    def add(self, num: int) -> None:
        if num == 0:
            # If a 0 is added, all prefix products before become invalid
            self.prefix_product = [1]
        else:
            self.prefix_product.append(self.prefix_product[-1] * num)

    def getProduct(self, k: int) -> int:
        if k >= len(self.prefix_product):
            # k == n also returns 0 because there is a leading 1 in the array
            return 0
        # n = len(self.prefix_product)
        # return self.prefix_product[n - 1] // self.prefix_product[n - 1 - k]
        return self.prefix_product[-1] // self.prefix_product[-k - 1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
# @lc code=end

