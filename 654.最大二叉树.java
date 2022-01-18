/*
 * @lc app=leetcode.cn id=654 lang=java
 *
 * [654] 最大二叉树
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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return helper(nums, 0, nums.length - 1);
    }

    private TreeNode helper(int[] nums, int l, int r) {
        if (l > r)  return null;
        int argmax = -1, max = Integer.MIN_VALUE;
        for (int i = l; i <= r; ++i) {
            if (max < nums[i]) {
                argmax = i;
                max = nums[i];
            }
        }

        TreeNode root = new TreeNode(max);
        root.left = helper(nums, l, argmax - 1);
        root.right = helper(nums, argmax + 1, r);
        
        return root;
    }
}
// @lc code=end

