/*
 * @lc app=leetcode.cn id=968 lang=java
 *
 * [968] 监控二叉树
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
    private static enum State {
        UNCOVERED,
        COVERED_WO_CAM,
        COVERED_W_CAM
    }

    private int ans;

    public int minCameraCover(TreeNode root) {
        ans = 0;
        if (postOrder(root) == State.UNCOVERED) {
            // Root's children are covered without a camera,
            // but the root itself is uncovered 
            return ans + 1;
        }
        return ans;
    }

    private State postOrder(TreeNode node) {
        if (node == null)  return State.COVERED_WO_CAM;
        State leftState = postOrder(node.left);
        State rightState = postOrder(node.right);
        if (leftState == State.UNCOVERED || rightState == State.UNCOVERED) {
            ++ans;
            return State.COVERED_W_CAM;
        }
        if (leftState == State.COVERED_W_CAM || rightState == State.COVERED_W_CAM) {
            return State.COVERED_WO_CAM;
        }
        // States of children both equal State.COVERED_WO_CAM
        return State.UNCOVERED;
    }
}
// @lc code=end

