import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=199 lang=java
 *
 * [199] 二叉树的右视图
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
    // BFS
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)  return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = q.poll();
                if (node.left != null)  q.offer(node.left);
                if (node.right != null)  q.offer(node.right);
                if (i == size - 1)  res.add(node.val);
            }
        }
        return res;
    }
}
// @lc code=end

