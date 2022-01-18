/*
 * @lc app=leetcode.cn id=99 lang=java
 *
 * [99] 恢复二叉搜索树
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
    public void recoverTree(TreeNode root) {
        // Morris traversal: if node has left child (subtree) visit twice, otherwise visit once.
        TreeNode x = null, y = null, pre = null, tmp = null;

        while (root != null) {
            if (root.left != null) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                tmp = root.left;
                while (tmp.right != null && tmp.right != root) {
                    tmp = tmp.right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (tmp.right == null) {
                    tmp.right = root;
                    root = root.left;
                } else {
                    // 说明左子树已经访问完了，我们需要断开链接
                    if (pre != null && root.val < pre.val) {
                        y = root;
                        if (x == null) {
                            x = pre;
                        }
                    }
                    pre = root;

                    tmp.right = null;
                    root = root.right;
                }
            } else {
                // 如果没有左孩子，则直接访问右孩子
                if (pre != null && root.val < pre.val) {
                    y = root;
                    if (x == null) {
                        x = pre;
                    }
                }
                pre = root;
                root = root.right;
            }
        }
        swap(x, y);
    }

    private void swap(TreeNode x, TreeNode y) {
        int tmp = x.val;
        x.val = y.val;
        y.val = tmp;
    }
}
// @lc code=end

