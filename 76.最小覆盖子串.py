#
# @lc app=leetcode.cn id=76 lang=python3
#
# [76] 最小覆盖子串
#
from collections import defaultdict

# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = defaultdict(int)
        for c in t:
            need[c] += 1
        need_cnt = len(t)
        left = 0
        res = (0, float('inf'))
        for right, c in enumerate(s):
            if need[c] > 0:
                need_cnt -= 1
            need[c] -= 1
            if not need_cnt:       # 步骤一：滑动窗口包含了所有T元素
                while True:      # 步骤二：增加i，排除多余元素
                    c = s[left] 
                    if not need[c]:
                        # 遇到了一个在`T`中的元素
                        break
                    need[c] += 1
                    left += 1
                if right - left < res[1] - res[0]:   
                    # 找到了更短的，记录结果
                    res = (left, right)
                    
                # 步骤三：i增加一个位置，寻找新的满足条件滑动窗口
                need[s[left]] += 1
                need_cnt += 1
                left += 1
        # 如果res始终没被更新过，代表无满足条件的结果
        return '' if res[1] > len(s) else s[res[0]:res[1]+1]


# @lc code=end
