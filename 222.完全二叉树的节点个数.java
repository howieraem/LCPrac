/*
 * @lc app=leetcode.cn id=222 lang=java
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int countNodes(TreeNode root) {
        // time complexity O(logN*logN)
        TreeNode l = root, r = root;
        int hl = 0, hr = 0;
        while (l != null) {
            l = l.left;
            ++hl;
        }
        while (r != null) {
            r = r.right;
            ++hr;
        }
        // At least one of the subtrees of a complete binary tree 
        // is a full binary tree
        return hl == hr ? 
            (int) Math.pow(2, hl) - 1 : 
            1 + countNodes(root.left) + countNodes(root.right);
    }
}
// @lc code=end

