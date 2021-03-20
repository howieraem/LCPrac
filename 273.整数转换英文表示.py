#
# @lc app=leetcode.cn id=273 lang=python3
#
# [273] 整数转换英文表示
#
from collections import deque

# @lc code=start
class Solution:
    THOUSAND = ["", "Thousand", "Million", "Billion",]  # "Trillion"]
    HUNDRED = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
    LESS_THAN_20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]

    def numberToWords(self, num: int) -> str:
        if not num:
            return "Zero"
        i = 0
        ans = deque()
        while num > 0:
            if num % 1000:
                string = self.helper(num % 1000, "")
                ans.appendleft(string + Solution.THOUSAND[i] + " ")
            i += 1
            num //= 1000
        return "".join(ans).rstrip()

    def helper(self, num: int, string: str):
        if not num:
            return string
        if num < 20:
            string += Solution.LESS_THAN_20[num] + " "
        elif num < 100:
            string += Solution.HUNDRED[num // 10] + " "
            string = self.helper(num % 10, string)
        else:
            string += Solution.LESS_THAN_20[num // 100] + " Hundred "
            string = self.helper(num % 100, string)  
        return string

# @lc code=end

