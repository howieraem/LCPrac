#
# @lc app=leetcode id=165 lang=python3
#
# [165] Compare Version Numbers
#

# @lc code=start
class Solution:
    # T: O(max(len(v1), len(v2)))
    # S: O(len(v1) + len(v2))
    def compareVersion(self, version1: str, version2: str) -> int:
        v1s = version1.split('.')
        n1 = len(v1s)
        v2s = version2.split('.')
        n2 = len(v2s)
        i = 0
        j = 0
        while i < n1 or j < n2:
            v1 = int(v1s[i]) if i < n1 else 0
            v2 = int(v2s[j]) if j < n2 else 0
            if v1 < v2:
                return -1
            elif v1 > v2:
                return 1
            i += 1
            j += 1
        return 0


# @lc code=end

