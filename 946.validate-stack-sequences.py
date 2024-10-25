#
# @lc app=leetcode id=946 lang=python3
#
# [946] Validate Stack Sequences
#
from typing import List

# @lc code=start
class Solution:
    # Stack simulation / two pointers
    # T: O(n)
    # S: O(n) if can't modify input, or O(1)
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        # st = []
        i = 0
        j = 0

        for x in pushed:
            # st.append(x)
            pushed[i] = x
            i += 1

            # while len(st) > 0 and st[-1] == popped[j]:
                # st.pop()
                # j += 1
            while i > 0 and pushed[i - 1] == popped[j]:
                i -= 1
                j += 1

        # return len(st) == 0
        return i == 0
        
# @lc code=end

