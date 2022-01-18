#
# @lc app=leetcode.cn id=96 lang=python3
#
# [96] 不同的二叉搜索树
#


# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        """Solution with Catalan numbers. Let G(n) be the number of 
        possible binary search trees (BST's) with 1...n as nodes. 
        Let f(i) be the number of possible BST's with i as the root 
        where 1 <= i <= n. Then we have f(i) = G(i-1)*G(n-i) which is 
        the product of numbers of possible BST's of left and right
        children respectively. Therefore: G(n) = G(1) + ... + G(n) 
        = G(0)*G(n-1) + ... + G(n-1)*G(0)
        """
        G = [0]*(n+1)
        G[0:2] = 1

        for i in range(2, n+1):
            for j in range(1, i+1):
                G[i] += G[j-1] * G[i-j]

        return G[n]

# @lc code=end
s = Solution()
print(s.numTrees(5))
