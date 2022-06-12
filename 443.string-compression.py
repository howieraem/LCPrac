#
# @lc app=leetcode id=443 lang=python3
#
# [443] String Compression
#
from typing import List

# @lc code=start
class Solution:
    # T: O(N)
    # S: O(1)
    def compress(self, chars: List[str]) -> int:
        N = len(chars)
        i = j = 0

        while i < N:
            cur = chars[i]
            cnt = 1
            i += 1
            while i < N and chars[i] == cur:
                i += 1
                cnt += 1
            
            chars[j] = cur
            j += 1

            if cnt > 1:

                # If cnt > 10, need to reverse the digits
                k1 = j
                while cnt != 0:
                    chars[j] = str(cnt % 10)
                    cnt //= 10
                    j += 1
                k2 = j - 1
                
                # Below is O(1) space and faster than chars[k1:j] = reversed(chars[k1:j])
                while k1 < k2:
                    chars[k1], chars[k2] = chars[k2], chars[k1]
                    k1 += 1
                    k2 -= 1

        return j
        
# @lc code=end

