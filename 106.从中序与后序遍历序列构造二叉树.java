/*
 * @lc app=leetcode.cn id=106 lang=java
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return helper(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }

    private TreeNode helper(int[] in, int inL, int inR, 
                            int[] post, int postL, int postR) {
        if (inL > inR)  return null;

        int rootVal = post[postR], rootIdxIn = -1;
        for (int i = inL; i <= inR; ++i) {
            if (in[i] == rootVal) {
                rootIdxIn = i;
                break;
            }
        }
        
        int leftSubTreeSize = rootIdxIn - inL;
        TreeNode root = new TreeNode(rootVal);
        root.left = helper(in, inL, rootIdxIn - 1, post, postL, postL + leftSubTreeSize - 1);
        root.right = helper(in, rootIdxIn + 1, inR, post, postL + leftSubTreeSize, postR - 1);
        return root;
    }
}
// @lc code=end

