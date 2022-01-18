#
# @lc app=leetcode.cn id=301 lang=python3
#
# [301] 删除无效的括号
#

# @lc code=start
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def isValid(s):
            count = 0
            for c in s:
                if c == '(':
                    count += 1
                elif c == ')':
                    count -= 1
                if count < 0:
                    return False
            return not count

        # BFS
        level = {s}  # 用set避免重复
        while True:
            valid = [s for s in level if isValid(s)]  # 所有合法字符都筛选出来
            if valid: 
                # 如果当前valid是非空的，说明已经有合法的产生了
                return valid
            # 下一层level
            next_level = set()
            for item in level:
                for i in range(len(item)):
                    if item[i] in '()':     # note that `s` might contain other characters
                        next_level.add(item[:i]+item[i+1:])     # remove current character
            level = next_level
        
# @lc code=end
