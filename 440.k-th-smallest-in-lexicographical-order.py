#
# @lc app=leetcode id=440 lang=python3
#
# [440] K-th Smallest in Lexicographical Order
#

# @lc code=start
class Solution:
    # T: O((log(n)) ^ 2)
    # S: O(1)
    def findKthNumber(self, n: int, k: int) -> int:
        cur = 1
        k -= 1
        while k > 0:
            gap = self.get_gap(n, cur, cur + 1)
            if gap <= k:
                cur += 1
                k -= gap
            else:
                # example: n = 13, cur = 1, gap = 5 > k = 2 
                # -> new_cur = 10
                cur *= 10
                k -= 1
        return cur

    def get_gap(self, n: int, pre: int, nxt: int) -> int:
        ans = 0
        while pre <= n:
            # if n + 1 > nxt: gap = nxt - pre
            # else: gap = n + 1 - pre
            # Example: n = 13, pre = 1, nxt = 2
            # gap = (2 - 1) + (14 - 1 * 10) = 5
            ans += min(n + 1, nxt) - pre

            pre *= 10
            nxt *= 10
        return ans
        
# @lc code=end

