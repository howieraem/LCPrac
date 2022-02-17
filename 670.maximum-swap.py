#
# @lc app=leetcode id=670 lang=python3
#
# [670] Maximum Swap
#

# @lc code=start
class Solution:
    # T: O(log10(num))
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        last_idxs = [-1] * 10
        for i, x in enumerate(s):
            last_idxs[int(x)] = i

        for i, x in enumerate(s):
            for j in range(9, int(x), -1):
                k = last_idxs[j]
                if k > i:
                    s[i], s[k] = s[k], s[i]
                    return int("".join(s))
        return num
        
# @lc code=end

