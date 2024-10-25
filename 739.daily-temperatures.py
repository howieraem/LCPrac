#
# @lc app=leetcode id=739 lang=python3
#
# [739] Daily Temperatures
#
from typing import List

# @lc code=start
class Solution:
    # Mono-stack
    # T: O(n)
    # S: O(n)
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        st = []
        res = [0] * n

        for i in range(n):
            # mono-stack storing indices of corresponding numbers ordered DESC
            while len(st) > 0 and temperatures[st[-1]] < temperatures[i]:
                pre_i = st.pop()
                res[pre_i] = i - pre_i

            st.append(i)

        return res

# @lc code=end

