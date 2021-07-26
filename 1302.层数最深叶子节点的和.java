import java.util.*;
/*
 * @lc app=leetcode.cn id=1302 lang=java
 *
 * [1302] 层数最深叶子节点的和
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
    // public int deepestLeavesSum(TreeNode root) {
    //     if (root == null)  return 0;
    //     Queue<TreeNode> q = new ArrayDeque<>();
    //     q.offer(root);
    //     int ans = 0;
    //     while (!q.isEmpty()) {
    //         ans = 0;
    //         int n = q.size();
    //         for (int i = 0; i < n; ++i) {
    //             TreeNode node = q.poll();
    //             // if (node == null)  continue;
    //             ans += node.val;
    //             if (node.left != null)  q.offer(node.left);
    //             if (node.right != null)  q.offer(node.right);
    //         }
    //     }
    //     return ans;
    // }

    int maxLevel, ans;

    public int deepestLeavesSum(TreeNode root) {
        maxLevel = 0;
        ans = 0;
        helper(root, 0);
        return ans;
    }

    private void helper(TreeNode node, int lvl) {
        if (node == null)  return;
        if (lvl > maxLevel) {
            ans = node.val;
            maxLevel = lvl;
        } else if (lvl == maxLevel) {
            ans += node.val;
        }
        helper(node.left, lvl + 1);
        helper(node.right, lvl + 1);
    }
}
// @lc code=end

