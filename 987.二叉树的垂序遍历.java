import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

/*
 * @lc app=leetcode.cn id=987 lang=java
 *
 * [987] 二叉树的垂序遍历
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
    Map<Integer, Map<Integer, Integer>> d;

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        d = new TreeMap<>();
        traverse(root, 0, 0);

        List<List<Integer>> res = new ArrayList<>();
        // Use tree maps to keep the order of columns and their contents
        for (Map.Entry<Integer, Map<Integer, Integer>> c : d.entrySet()) {
            Map<Integer, Integer> column = c.getValue();
            List<Integer> colRes = new ArrayList<>();
            for (Map.Entry<Integer, Integer> e : column.entrySet()) {
                for (int i = 0; i < e.getValue(); ++i) {
                    colRes.add(e.getKey() % 10000);
                }
            }
            res.add(colRes);
        }
        return res;
    }

    private void traverse(TreeNode root, int row, int col) {
        if (root == null)  return;
        Map<Integer, Integer> column = d.computeIfAbsent(col, k -> new TreeMap<>());
        // Column results ordered by row and if same row by value
        int key = row * 10000 + root.val;
        // In case duplicate values exist, need to store the count as well
        column.put(key, column.getOrDefault(key, 0) + 1);
        ++row;
        traverse(root.left, row, col - 1);
        traverse(root.right, row, col + 1);
    }
}
// @lc code=end

