from collections import defaultdict
from typing import List

class Solution:
    # T: O(n ^ 2) worst case?
    # S: O(n)
    def maximumLength(self, nums: List[int]) -> int:
        cnts = defaultdict(int)
        for x in nums:
            cnts[x] += 1
        
        ans = 1

        # special case: pattern starts and ends with 1
        cnt1 = cnts.get(1, None)
        if cnt1 is not None:
            ans = cnt1 - 1 if (cnt1 & 1) == 0 else cnt1
        
        for x in nums:
            if x == 1:
                # already covered above
                continue
            
            length = 0
            while cnts[x] >= 2 and x * x in cnts:
                length += 2
                x *= x

            # Don't forget the last x which can be single only
            # (the max middle element)
            length += 1
            ans = max(ans, length)
        
        return ans
