/*
 * @lc app=leetcode.cn id=1448 lang=java
 *
 * [1448] 统计二叉树中好节点的数目
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
    private int ans;

    public int goodNodes(TreeNode root) {
        ans = 0;
        dfs(root, Integer.MIN_VALUE);
        return ans;
    }

    private void dfs(TreeNode root, int max) {
        if (root.val >= max) {
            max = root.val;
            ++ans;
        }
        if (root.left != null)  dfs(root.left, max);
        if (root.right != null)  dfs(root.right, max);
    }
}
// @lc code=end

