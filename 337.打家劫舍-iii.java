import java.util.Map;
import java.util.HashMap;
/*
 * @lc app=leetcode.cn id=337 lang=java
 *
 * [337] 打家劫舍 III
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

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
    private Map<TreeNode, Integer> memo;

    public int rob(TreeNode root) {
        memo = new HashMap<>();
        return helper(root);
    }

    private int helper(TreeNode root) {
        if (root == null)  return 0;
        if (memo.containsKey(root))  return memo.get(root);
        int case_rob = root.val
            + (root.left == null ? 0 : helper(root.left.left) + helper(root.left.right))
            + (root.right == null ? 0 : helper(root.right.left) + helper(root.right.right));
        int case_not_rob = helper(root.left) + helper(root.right);
        int ans = Math.max(case_rob, case_not_rob);
        memo.put(root, ans);
        return ans;
    }
}
// @lc code=end

