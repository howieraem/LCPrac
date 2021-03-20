import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode.cn id=230 lang=java
 *
 * [230] 二叉搜索树中第K小的元素
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
class Solution {
    /*
    private int rank, res;

    public int kthSmallest(TreeNode root, int k) {
        rank = 0;
        traverse(root, k);
        return res;
    }

    private void traverse(TreeNode root, int k) {
        if (root == null)  return;
        traverse(root.left, k);
        ++rank;
        if (rank == k) {
            res = root.val;
            return;
        }
        traverse(root.right, k);
    }
    */
    public int kthSmallest(TreeNode root, int k) {
        // non-recursive in-order traversal with stack
        Stack<TreeNode> s = new Stack<>();
        while (true) {
            while (root != null) {
                s.add(root);
                root = root.left;
            }
            root = s.pop();
            --k;
            if (k == 0)  return root.val;
            root = root.right;
        }
    }
}
// @lc code=end

