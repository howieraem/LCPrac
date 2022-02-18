#
# @lc app=leetcode id=670 lang=python3
#
# [670] Maximum Swap
#

# @lc code=start
class Solution:
    # T: O(log10(num))
    # S: O(log10(num))
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))      # convert to string
        last_idxs = [-1] * 10
        for i, x in enumerate(s):
            last_idxs[int(x)] = i   # get the last indexes for each digit

        for i, x in enumerate(s):
            for j in range(9, int(x), -1):
                # See if the current digit can be swapped with a greater one after
                k = last_idxs[j]
                if k > i:
                    s[i], s[k] = s[k], s[i]
                    return int("".join(s))
        return num  # unable to find the swap

# @lc code=end

