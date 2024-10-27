#
# @lc app=leetcode id=1442 lang=python3
#
# [1442] Count Triplets That Can Form Two Arrays of Equal XOR
#
from collections import defaultdict
from typing import List

# @lc code=start
class Solution:
    # Prefix XOR (variant of prefix sum)
    # T: O(n) after math simplification
    # S: O(n) 
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        prefix_xor = [0] * (n + 1)

        for i in range(1, n + 1):
            prefix_xor[i] = prefix_xor[i - 1] ^ arr[i - 1]

        # Math: 
        #   a = b
        #   a ^ b = a ^ a = 0
        #   arr[i] ^ arr[i + 1] ^ ... ^ arr[j] ^ ... ^ arr[k] = 0
        #   prefix_xor[k + 1] - prefix_xor[i] = 0

        ans = 0
        """
        # O(n ^ 2) approach: find how many pairs of (i, k) with equal prefix_xor
        for i in range(n + 1):    
            for k in range(i + 1, n + 1):
                if prefix_xor[i] == prefix_xor[k]:
                    # i < j <= k, there are (k - i - 1) possibilities of j
                    ans += k - i - 1
        """

        # O(n) approach: 
        # For every xor(a[i...j]) = 0, we add j - i - 1
        # If there are multiple j's meeting this condition:
        #   ans = (i - j1 - 1) + (i - j2 - 1) + ...
        #       = freq * (i - 1) - sum(j1, j2, ...)
        # We can count the frequency of prefix_xor and sum the indices up,
        # and add to the answer
        prefix_xor_freqs = defaultdict(int)
        prefix_xor_freqs[0] = 1
        prefix_xor_idx_sum = defaultdict(int)
        for i in range(1, n + 1):
            prefix = prefix_xor[i]
            ans += (i - 1) * prefix_xor_freqs[prefix] - prefix_xor_idx_sum[prefix]
            prefix_xor_freqs[prefix] += 1
            prefix_xor_idx_sum[prefix] += i
        return ans

# @lc code=end

