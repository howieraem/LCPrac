/*
 * @lc app=leetcode.cn id=173 lang=java
 *
 * [173] 二叉搜索树迭代器
 */
import java.util.Stack;

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

 /** In-order traversal with O(h) space. */
class BSTIterator {
    private Stack<TreeNode> s;

    public BSTIterator(TreeNode root) {
        s = new Stack<>();
        leftMostInOrder(root);
    }

    private void leftMostInOrder(TreeNode root) {
        while (root != null) {
            s.push(root);
            root = root.left;
        }
    }
    
    /** 
     * Simulates the in-order traversal (originally recursion) with a stack.
     * In-order traversal: left -> mid -> right
     * 
     * @return the next smallest number 
     */
    public int next() {
        TreeNode top = s.pop();
        if (top.right != null) {
            leftMostInOrder(top.right);
        }
        return top.val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !s.empty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
// @lc code=end

