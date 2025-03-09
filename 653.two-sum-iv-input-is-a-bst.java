/*
 * @lc app=leetcode id=653 lang=java
 *
 * [653] Two Sum IV - Input is a BST
 */

import java.util.HashSet;
import java.util.Set;

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
    // Hash Map
    // T: O(n)
    // S: O(n)
    public boolean findTarget(TreeNode root, int k) {
        return dfs(root, new HashSet<>(), k);
    }

    private boolean dfs(TreeNode root, Set<Integer> vis, final int k) {
        if (root == null) {
            return false;
        }

        int d = k - root.val;
        if (vis.contains(d)) {
            return true;
        }
        vis.add(root.val);
        return dfs(root.left, vis, k) || dfs(root.right, vis, k);
    }
}
// @lc code=end

