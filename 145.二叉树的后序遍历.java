/*
 * @lc app=leetcode.cn id=145 lang=java
 *
 * [145] 二叉树的后序遍历
 */
import java.util.*;

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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)  return res;
        Stack<Object> s = new Stack<>();
        s.push(root);
        while (!s.empty()) {
            Object o = s.pop();
            if (o instanceof TreeNode) {
                TreeNode node = (TreeNode) o;
                // As stack is LIFO, push order is cur, right, left
                s.push(node.val); 
                if (node.right != null) s.push(node.right);
                if (node.left != null) s.push(node.left); 
            } else {
                res.add((int) o);
            }
        }
        return res;
    }
}
// @lc code=end

