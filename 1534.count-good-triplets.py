#
# @lc app=leetcode id=1534 lang=python3
#
# [1534] Count Good Triplets
#
from typing import List

# @lc code=start
class Solution:
    # Brute-Force
    # T: O(n ^ 3)
    # S: O(1)
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        ans = 0
        
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                if abs(arr[i] - arr[j]) <= a:
                    for k in range(j + 1, n):
                        ans += (abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c)
        
        return ans


# @lc code=end

