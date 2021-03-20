#
# @lc app=leetcode.cn id=241 lang=python3
#
# [241] 为运算表达式设计优先级
#

# @lc code=start
class Solution:
    OPS = {'+', '-', '*'}

    def diffWaysToCompute(self, input: str) -> List[int]:
        # divide-and-conquer (binary tree post-order traversal)
        if input.isdigit():
            return [int(input)]
        
        res = []
        for i, c in enumerate(input):
            if c in Solution.OPS:
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i + 1:])

                for l in left:
                    for r in right:
                        if c == '+':
                            res.append(l + r)
                        elif c == '-':
                            res.append(l - r)
                        else:
                            res.append(l * r)
        return res

# @lc code=end

