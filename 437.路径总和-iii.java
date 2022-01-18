import java.util.*;
/*
 * @lc app=leetcode.cn id=437 lang=java
 *
 * [437] 路径总和 III
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
    private int ans = 0;

    public int pathSum(TreeNode root, int targetSum) {
        if (root == null)  return ans;

        // process the root node and then its children recursively
        sum(root, targetSum);
        pathSum(root.left, targetSum);
        pathSum(root.right, targetSum);

        return ans;
    }

    private void sum(TreeNode root, int cur) {
        if (root == null)  return;
        cur -= root.val;
        if (cur == 0)   ++ans; 
        sum(root.left, cur);
        sum(root.right, cur);
    }
}
// @lc code=end

