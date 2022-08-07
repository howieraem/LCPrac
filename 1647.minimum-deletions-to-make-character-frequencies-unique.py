#
# @lc app=leetcode id=1647 lang=python3
#
# [1647] Minimum Deletions to Make Character Frequencies Unique
#
from collections import Counter

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(s), s := alphabet size
    def minDeletions(self, s: str) -> int:
        cnts = Counter(s)
        ans = 0
        existing_cnts = set()
        for cnt in cnts.values():
            while cnt > 0 and cnt in existing_cnts:
                cnt -= 1
                ans += 1
            existing_cnts.add(cnt)
        return ans
        
# @lc code=end

