#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#
from typing import List

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        visited = dict()
        for s in strs:
            # Note: for better time complexity than sorting characters, one may also 
            #   use character counts as keys, but space usage can be worse
            ss = ''.join(sorted(s))
            if ss in visited.keys():
                visited[ss].append(s)
            else:
                visited[ss] = [s]
        return list(visited.values())

# @lc code=end
s = Solution()
print(s.groupAnagrams(['eat', 'tea', 'tan', 'ate', 'nat', 'bat']))
