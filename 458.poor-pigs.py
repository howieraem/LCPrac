#
# @lc app=leetcode id=458 lang=python3
#
# [458] Poor Pigs
#

# @lc code=start
class Solution:
    # Some explanations: 
    #   https://leetcode.com/problems/poor-pigs/discuss/94266
    #   https://leetcode.com/problems/poor-pigs/discuss/94305
    # T: O(log(buckets))
    # S: O(1)
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        # The number of tests allowed T = floor(minutesToTest / minutesToDie).
        # For each pig during T tests, it has exactly T + 1 states: 
        # dies at the i-th test (1 <= i <= T), or still alive eventually.
        # For x pigs, the maximum total number of states is (T + 1) ^ x,
        # since each pig's well-being solely depends on whether the pig is 
        # ever fed on poison bucket and nothing to do with other pigs.
        # Thus, find the minimum x such that (T + 1) ^ x >= buckets.
        states_per_pig = minutesToTest // minutesToDie + 1
        ans = 0
        while states_per_pig ** ans < buckets:
            ans += 1
        return ans

# @lc code=end

