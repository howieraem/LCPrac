import java.util.*;
/*
 * @lc app=leetcode.cn id=1339 lang=java
 *
 * [1339] 分裂二叉树的最大乘积
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private List<Long> sums;
    private static final int F = (int) 1e9 + 7;

    public int maxProduct(TreeNode root) {
        sums = new ArrayList<>();
        sumTree(root);
        long ans = -1;
        long rootSum = sums.get(sums.size() - 1);
        for (int i = 0; i < sums.size(); ++i) {
            ans = Math.max(ans, sums.get(i) * (rootSum - sums.get(i)));
        }
        return (int) (ans % F);
    }

    private long sumTree(TreeNode root) {
        if (root == null)  return 0;
        long res = root.val + sumTree(root.left) + sumTree(root.right);
        sums.add(res);
        return res;
    }
}
// @lc code=end

