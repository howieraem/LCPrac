#
# @lc app=leetcode id=904 lang=python3
#
# [904] Fruit Into Baskets
#
from typing import List

# @lc code=start
class Solution:
    # Sliding window
    # T: O(n)
    # S: O(k), k := 2
    def totalFruit(self, fruits: List[int]) -> int:
        K = 2
        freqs = dict()
        ans = 0
        l = 0
        for r in range(len(fruits)):
            freqs[fruits[r]] = freqs.get(fruits[r], 0) + 1

            while len(freqs) > K:
                freqs[fruits[l]] -= 1
                if freqs[fruits[l]] == 0:
                    del freqs[fruits[l]]
                l += 1
            
            ans = max(ans, r - l + 1)
        
        return ans


# @lc code=end

