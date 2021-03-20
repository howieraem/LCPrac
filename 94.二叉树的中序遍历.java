/*
 * @lc app=leetcode.cn id=94 lang=java
 *
 * [94] 二叉树的中序遍历
 */
import java.util.*;

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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root==null)  return res;
        Stack<Object> stack = new Stack<>();
        stack.push(root);
        while (!stack.empty()) {
            Object o = stack.pop();
            if (o instanceof TreeNode) {
                TreeNode node = (TreeNode) o;
                // 因为中序遍历是左节点--根节点--右节点
                // 即出栈顺序为左节点--根节点--右节点，入栈顺序相反
                if (node.right != null) stack.push(node.right);
                stack.push(node.val); 
                if (node.left != null) stack.push(node.left); 
            } else {
                res.add((int) o);
            }
       }
       return res;  
    }
}
// @lc code=end

