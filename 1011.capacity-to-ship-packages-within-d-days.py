#
# @lc app=leetcode id=1011 lang=python3
#
# [1011] Capacity To Ship Packages Within D Days
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * log(sum(weights)))
    # S: O(1)
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        # Find the range for binary search
        # - minimum is the maximum single package weight
        # - maximum is the sum of all package weights (ship in just 1 day)
        l, r = 0, 0
        for w in weights:
            l = max(l, w)
            r += w

        # Find the lower bound of cap via binary search
        while l < r:
            m = l + ((r - l) >> 1)

            day_weight = 0
            days_req = 1
            for w in weights:
                if day_weight + w > m:
                    # exceed current capacity, have to ship next day
                    days_req += 1
                    day_weight = 0
                day_weight += w

            # too many days required, not enough capacity
            if days_req > days:
                l = m + 1
            else:
                r = m

        return l

# @lc code=end

