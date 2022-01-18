/*
 * @lc app=leetcode.cn id=108 lang=java
 *
 * [108] 将有序数组转换为二叉搜索树
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
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(nums, 0, nums.length-1);
    }

    private TreeNode helper(int[] nums, int left, int right) {
        if (left > right)  return null;
        // Always choose the mid-left as root of subtree, though mid-right would also be valid.
        // The binary search tree recovered from a sorted array is not unique.
        int mid = left + (right - left) / 2;    // change to `(right - left + 1) / 2` for mid-right
        TreeNode root = new TreeNode(nums[mid]);
        root.left = helper(nums, left, mid-1);
        root.right = helper(nums, mid+1, right);
        return root;
    }
}
// @lc code=end

