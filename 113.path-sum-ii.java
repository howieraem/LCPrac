import java.util.*;

/*
 * @lc app=leetcode id=113 lang=java
 *
 * [113] Path Sum II
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
    List<List<Integer>> res;

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        res = new ArrayList<>();
        backtrack(root, new Stack<>(), targetSum);
        return res;
    }

    private void backtrack(TreeNode node, Stack<Integer> path, int targetSum) {
        if (node == null)  return;
        path.add(node.val);
        if (node.left == null && node.right == null && node.val == targetSum) {
            res.add(new ArrayList<>(path));
        } else {
            backtrack(node.left, path, targetSum - node.val);
            backtrack(node.right, path, targetSum - node.val);
        }
        path.pop();
    }
}
// @lc code=end

