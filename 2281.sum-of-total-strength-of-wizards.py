from typing import List


class Solution:
    # Prefix sum and mono-stack
    # T: O(n)
    # S: O(n)
    def totalStrength(self, strength: List[int]) -> int:
        MOD = 10 ** 9 + 7
        n = len(strength)

        # Mono-stack for finding subarray minima
        # find next smaller to the right
        nxt_small_r = [n] * n
        stack = []
        for i in range(n):
            while len(stack) > 0 and strength[stack[-1]] > strength[i]:
                nxt_small_r[stack.pop()] = i
            stack.append(i)

        # find next smaller to the left
        nxt_small_l = [-1] * n
        stack = []
        for i in range(n - 1, -1, -1):
            while len(stack) > 0 and strength[stack[-1]] >= strength[i]:
                nxt_small_l[stack.pop()] = i
            stack.append(i)

        # Prefix sum for finding subarray sums
        prefix_sums = [0] * (n + 1)
        for i in range(n):
            prefix_sums[i + 1] = prefix_sums[i] + strength[i]
        prefix_prefix_sums = [0] * (n + 1)  # considers all subarrays
        for i in range(n):
            prefix_prefix_sums[i + 1] = prefix_prefix_sums[i] + prefix_sums[i + 1]

        # Calculate total strength
        ans = 0
        for i in range(n):
            l = nxt_small_l[i]
            r = nxt_small_r[i]
            n_l = i - l
            n_r = r - i
            sum_l = prefix_prefix_sums[i] - prefix_prefix_sums[max(l, 0)]
            sum_r = prefix_prefix_sums[r] - prefix_prefix_sums[i]
            
            # Sum up all subarrays between l and r with strength[i] as the minimum strength.
            # Explanation: 
            #   Suppose this array[l...r]'s indices are: a1, a2, a3, ... aL, aW, b1, b2, b3..., bR, 
            #   with A[aW] be the smallest. 
            #
            #   Now we can pick any index ai from a1 to aL, and any index bj from b1 to bR to form an array 
            #   such that this array is using aW as the min value. 
            #   If we have a prefix sum array, then this particular pick score would be 
            #   A[aW] * (sum[bj] - sum[ai]).
            #
            #   How many combinations of (ai, bj) are there? 
            #   For any particular ai, it can be from sum[b1] to sum[bR], 
            #   so there will be n_l number of sum[b1] to sum[bR], i.e., 
            #   n_l * (sum[b1] + sum[b2] + ... sum[bR]); 
            #   Same idea for bj, we have n_r * (sum[a1] + sum[a2] + ... sum[aL]).
            #
            #   Total score using A[aW]: 
            #   A[aW] * (n_l * (sum[b1] + sum[b2] + ... sum[bR]) - n_r * (sum[a1] + sum[a2] + ... sum[aL])).
            ans += strength[i] * (sum_r * n_l - sum_l * n_r) % MOD

        return ans % MOD
