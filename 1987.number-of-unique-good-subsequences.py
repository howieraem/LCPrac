#
# @lc app=leetcode id=1987 lang=python3
#
# [1987] Number of Unique Good Subsequences
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        MOD = 1000000007
        ends_with_0 = 0
        ends_with_1 = 0
        has_0 = False
        for c in binary:
            if c == '1':
                # "1" itself is a valid subsequence, need to add 1
                ends_with_1 = (ends_with_0 + ends_with_1 + 1) % MOD
            else:
                # Though "0" itself is a valid subsequence, the valid subsequence cannot have leading zeros.
                # Thus, we consider the case of "0" only once and add it to the final answer if exists
                ends_with_0 = (ends_with_0 + ends_with_1) % MOD
                has_0 = True
        return (ends_with_0 + ends_with_1 + has_0) % MOD

# @lc code=end

