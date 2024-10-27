/*
 * @lc app=leetcode.cn id=979 lang=java
 *
 * [979] 在二叉树中分配硬币
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

    // Post-order traversal DFS
    // T: O(n)
    // S: O(n)
    public int distributeCoins(TreeNode root) {
        ans = 0;
        helper(root);
        return ans;
    }

    private int helper(TreeNode node) {
        if (node == null) {
            return 0;
        }

        node.val += helper(node.left);
        node.val += helper(node.right);

        // The goal is to set every node's value to 1.
        // Thus, `toMove = node.val - 1` coins need  
        // to be moved in/out for each node. If 
        // toMove > 0, move coins out. Otherwise, 
        // move coins in.
        int toMove = node.val - 1;
        ans += Math.abs(toMove);
        return toMove;
    }
}
// @lc code=end

