#
# @lc app=leetcode id=907 lang=python3
#
# [907] Sum of Subarray Minimums
#
from typing import List

# @lc code=start
class Solution:
    # Mono-stacks
    # T: O(n)
    # S: O(n)
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 1000000007

        n = len(arr)
        left_next_less_dist = [0] * n
        right_next_less_dist = [0] * n

        st = []
        for i in range(n):
            # mono-stack storing (x, i) with x ordered ASC
            while len(st) > 0 and st[-1][0] >= arr[i]:
                st.pop()

            if len(st) == 0:
                # handle edge cases like i = 0
                left_next_less_dist[i] = i + 1
            else:
                left_next_less_dist[i] = i - st[-1][1]

            st.append((arr[i], i))

        st.clear()
        for i in range(n - 1, -1, -1):
            # mono-stack storing (x, i) with x ordered DESC
            while len(st) > 0 and st[-1][0] > arr[i]:
                st.pop()
            
            if len(st) == 0:
                # handle edge cases like i = n - 1
                right_next_less_dist[i] = n - i
            else:
                right_next_less_dist[i] = st[-1][1] - i
            
            st.append((arr[i], i))

        ans = 0
        for i in range(n):
            # left_next_less_dist[i] * right_next_less_dist[i] is the number of subarrs 
            # with arr[i] as the minimum
            ans = (ans + arr[i] * left_next_less_dist[i] * right_next_less_dist[i]) % MOD
        return ans

# @lc code=end

