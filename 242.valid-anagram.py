#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#

# @lc code=start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # sorting
        # If alphabet size is much greater than string length
        # T: O(n * log(n))
        # S: O(n) timsort
        # if len(s) != len(t):
        #     return False
        # return sorted(s) == sorted(t)

        # hash map
        # If alphabet size is much smaller than string lengths
        # T: O(n + alpha_size)
        # S: O(alpha_size)
        if len(s) != len(t):
            return False
        
        cnts = [0] * 26
        for c1, c2 in zip(s, t):
            cnts[ord(c1) - ord('a')] += 1
            cnts[ord(c2) - ord('a')] -= 1
        
        return not any(cnts)   # all should be zero
        
# @lc code=end

