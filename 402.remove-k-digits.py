#
# @lc app=leetcode id=402 lang=python3
#
# [402] Remove K Digits
#

# @lc code=start
class Solution:
    # Conditional mono-stack
    # T: O(n)
    # S: O(1) reusing stack for res
    def removeKdigits(self, num: str, k: int) -> str:
        if k <= 0:
            return num
        
        n = len(num)
        if n == 0 or n <= k:
            return "0"
        
        st = []  # mono-stack with chars ordered ASC
        for i in range(n):
            while k > 0 and len(st) > 0 and st[-1] > num[i]:
                st.pop()
                k -= 1
        
            if len(st) == 0 and num[i] == "0":
                # IMPORTANT: avoid leading zeros
                continue

            st.append(num[i])

        while k > 0 and len(st) > 0:
            st.pop()
            k -= 1
        
        if len(st) == 0:
            # IMPORTANT
            return "0"

        return "".join(st)

            


# @lc code=end

