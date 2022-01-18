#
# @lc app=leetcode.cn id=451 lang=python3
#
# [451] 根据字符出现频率排序
#
from collections import defaultdict

# @lc code=start
class Solution:
    def frequencySort(self, s: str) -> str:
        # return ''.join([i * j for i, j in collections.Counter(s).most_common()])
        freq = defaultdict(int)
        for c in s:
            freq[c] += 1
        
        buckets = [[] for _ in range(len(s) + 1)]
        for k, v in freq.items():
            buckets[v].extend(k * v)
        
        ret = []
        for i in range(len(buckets) - 1, -1, -1):
            chars = buckets[i]
            if chars:
                ret.extend(chars)
        return ''.join(ret)

        
# @lc code=end

