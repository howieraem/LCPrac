#
# @lc app=leetcode id=1153 lang=python3
#
# [1153] String Transforms Into Another String
#

# @lc code=start
class Solution:
    # Greedy + hash map
    # T: O(n)
    # S: O(s), s := 26
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2:
            return True
        mapping = {}
        for c1, c2 in zip(str1, str2):
            if mapping.setdefault(c1, c2) != c2:
                # The same chars should have the same transformation.
                # If a different transformation exists, return false.
                return False

        # Assuming S1 is the set of chars in s1, and similar notation for S2.
        # For s1 to be transformable to s2, the condition |S1| >= |S2| needs 
        # to hold true because |S1| < |S2| means there is at least one character 
        # in s1 which maps to multiple characters (because lengths of s1 and s2 
        # are equal) and this makes s1 non-transformable to s2.
        # Also if |S1| == |S2| == 26 and s1 != s2, transformation is not possible 
        # because any transformation will create a circle. Need at least one char 
        # not in S2 (which acts like a tmp variable in swapping variable values) 
        # to make it transformable. 
        return len(set(str2)) < 26

# @lc code=end

