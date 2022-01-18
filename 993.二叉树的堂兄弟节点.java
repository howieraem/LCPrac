/*
 * @lc app=leetcode.cn id=993 lang=java
 *
 * [993] 二叉树的堂兄弟节点
 */

public class TreeNode {
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
    private int x, xDepth, y, yDepth;
    private TreeNode xParent, yParent;
    private boolean xFound, yFound;

    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        dfs(root, null, 0);
        return xDepth == yDepth && xParent != yParent;
    }

    private void dfs(TreeNode root, TreeNode parent, int depth) {
        if (root == null)  return;
        if (root.val == x) {
            xFound = true;
            xParent = parent;
            xDepth = depth;
        } else if (root.val == y) {
            yFound = true;
            yDepth = depth;
            yParent = parent;
        }

        if (xFound && yFound)  return;
        depth++;
        dfs(root.left, root, depth);
        if (xFound && yFound)  return;
        dfs(root.right, root, depth);
    }
}
// @lc code=end

