from typing import List

class Solution:
    # T: O(max(1, k - maxChanges) * len(nums))
    # S: O(len(nums))
    def minimumMoves(self, nums: List[int], k: int, maxChanges: int) -> int:
        # Suppose current index is x
        # Action 1 needs 2 moves to pick a one
        # Action 2 needs |y - x| moves to pick a one
        # If |y - x| > 2:
        #   action 1 will be optimal, but can only occur only maxChanges times, so 
        #   action 2 will occur k - maxChanges times
        # On the other hand, if |y - x| <= 1:
        #   action 2 will be optimal. So do action 2 k - maxChanges + 2 times instead,
        #   because we just have 3 y's for each x to satisfy |y - x| <= 1.
        idx1s = [i for i, x in enumerate(nums) if x == 1]
        ans = float('inf') if maxChanges < k else (k << 1)  # no need to do action 2

        n = len(idx1s)
        prefix_sums = idx1s[:]
        for i in range(1, n):
            prefix_sums[i] += prefix_sums[i - 1]

        def range_sum(l, r):
            return 0 if l > r else prefix_sums[r] if l == 0 else prefix_sums[r] - prefix_sums[l - 1]

        # Count minimum moves to take z ones if only using action 2
        min_n_action2 = max(1, k - maxChanges)
        for n_action2 in range(min_n_action2, min(k + 1, min_n_action2 + 3)):
            for l in range(n - n_action2 + 1):
                r = l + n_action2 - 1  # fixed-size sliding window
                m = l + ((r - l) >> 1)
                n_action = (k - n_action2) << 1  # n_action1
                n_action += range_sum(m + 1, r) - (r - m) * idx1s[m]
                n_action += (m - l) * idx1s[m] - range_sum(l, m - 1)
                ans = min(ans, n_action)
        
        return ans
