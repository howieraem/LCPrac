#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#
from typing import List

# @lc code=start
class Solution:
    _RULES = ("abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz")

    """
    def letterCombinations(self, digits: str) -> List[str]:
        # Most straight-forward approach: enumeration
        if not digits:
            return []
        ans = [""]
        for d in digits:
            # can use ASCII conversion (or `int(d)-1`) instead of dict
            ans = [s+c for s in ans for c in Solution._RULES[ord(d)-50]]
        return ans
    """

    def letterCombinations(self, digits: str) -> List[str]:
        """
        A more "scientific" approach: backtrack
        
        Notes: in this solution, result list does not need to be rebuilt.
        """
        if not digits: 
            return []
        res = []
        Solution.backtrack(res, '', digits)
        return res

    @staticmethod
    def backtrack(res, combination, next_d):
        if not next_d:   # len(next) == 0
            res.append(combination)
        else:
            for letter in Solution._RULES[ord(next_d[0])-50]:
                Solution.backtrack(res, combination+letter, next_d[1:])

# @lc code=end
s = Solution()
print(s.letterCombinations("23"))
