#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#
from typing import List

# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        """
        Solution based on DFS. Empty string `''` is the root node.
        A tree is built as the strings is building. Eligible leaf
        nodes will be collected.
        """
        res = []
        self.dfs(res, '', n, n)
        return res

    def dfs(self, res, cur_str, left, right):
        """
        :param cur_str: 从根结点到叶子结点的路径字符串
        :param left: 左括号还可以使用的个数
        :param right: 右括号还可以使用的个数
        """
        if not left and not right:
            res.append(cur_str)
            return
        if left > right:    # 非法，例如"())"，需剪枝
            return
        if left > 0:
            self.dfs(res, cur_str + '(', left - 1, right)
        if right > 0:
            self.dfs(res, cur_str + ')', left, right - 1)

# @lc code=end
