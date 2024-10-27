/*
 * @lc app=leetcode id=958 lang=java
 *
 * [958] Check Completeness of a Binary Tree
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
    // Level order traversal BFS
    // T: O(n)
    // S: O(n)
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        boolean end_of_level = false;
        while(!queue.isEmpty()) {
            TreeNode cur = queue.poll();
            if(cur == null) {
                // This should appear at most once for a complete binary tree.
                end_of_level = true;
            } else {
                if (end_of_level) {
                    return false;
                }
                queue.add(cur.left);
                queue.add(cur.right);
            }
        }
        return true;
    }
}
// @lc code=end

