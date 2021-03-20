/*
 * @lc app=leetcode.cn id=105 lang=java
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private TreeNode helper(int[] pre, int preL, int preR, 
                            int[] in, int inL, int inR) {
        if (preL > preR)  return null;

        int rootVal = pre[preL];
        int rootIdxIn = 0;
        for (int i = inL; i <= inR; ++i) {
            if (in[i] == rootVal) {
                rootIdxIn = i;
                break;
            }
        }

        int leftSubTreeSize = rootIdxIn - inL;
        TreeNode root = new TreeNode(rootVal);
        root.left = helper(pre, preL + 1, preL + leftSubTreeSize, in, inL, rootIdxIn - 1);
        root.right = helper(pre, preL + leftSubTreeSize + 1, preR, in, rootIdxIn + 1, inR);
        return root;
    }
}
// @lc code=end

