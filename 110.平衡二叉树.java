/*
 * @lc app=leetcode.cn id=110 lang=java
 *
 * [110] 平衡二叉树
 */

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
// A height-balanced binary tree is a binary tree 
// in which the depth of the two subtrees of every 
// node never differs by more than one.
class Solution {
    // Post-order traversal with pruning
    // T: O(n)
    // S: O(log(n)) if tree is balanced, otherwise O(n) worst case
    public boolean isBalanced(TreeNode root) {
        return helper(root) != -1;
    }

    public int helper(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left_depth = helper(root.left);
        if (left_depth == -1) {
            return -1;  // prune, reducing unnecessary computation
        }
        int right_depth = helper(root.right);
        if (right_depth == -1) {
            return -1;  // prune, reducing unnecessary computation
        }

        // Return the depth of the current subtree if it is still balanced,
        // otherwise -1.
        return Math.abs(right - left) <= 1 ? Math.max(left, right) + 1 : -1;
    }
}
// @lc code=end

