#
# @lc app=leetcode.cn id=140 lang=python3
#
# [140] 单词拆分 II
#
# from typing import List
from collections import deque

# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # Re-using code from question [139].
        n = len(s)
        dp = [True] + [False]*n
        for i in range(n):
            for j in range(i+1, n+1):
                if dp[i] and s[i:j] in wordDict:
                    dp[j] = True
        res = []
        if dp[-1]:
            def dfs(end, path):
                # note `appendleft` and `popleft` to keep the word order
                if s[:end+1] in wordDict:
                    path.appendleft(s[:end+1])
                    res.append(' '.join(path))
                    path.popleft()
                for i in range(end):
                    if dp[i+1]:
                        suffix = s[i+1:end+1]
                        if suffix in wordDict:
                            path.appendleft(suffix)
                            dfs(i, path)
                            path.popleft()
            dfs(n-1, deque())
        return res
            

# @lc code=end
# print(Solution().wordBreak('catsanddog', ['cat', 'cats', 'and', 'sand', 'dog']))
