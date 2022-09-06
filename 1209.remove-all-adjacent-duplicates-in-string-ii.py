#
# @lc app=leetcode id=1209 lang=python3
#
# [1209] Remove All Adjacent Duplicates in String II
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n) for result built from a mutable list of chars
    def removeDuplicates(self, s: str, k: int) -> str:
        n = len(s)
        cnt_of_char_at_idx = [0] * n
        res = [''] * n
        i = 0
        for j in range(n):
            res[i] = s[j]
            if i > 0 and res[i - 1] == s[j]:
                cnt_of_char_at_idx[i] = cnt_of_char_at_idx[i - 1] + 1 
            else: 
                cnt_of_char_at_idx[i] = 1
            if cnt_of_char_at_idx[i] == k:
                i -= k
            i += 1
        return "".join(res[:i])

# @lc code=end

