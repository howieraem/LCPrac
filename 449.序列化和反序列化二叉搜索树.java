import java.util.*;

/*
 * @lc app=leetcode.cn id=449 lang=java
 *
 * [449] 序列化和反序列化二叉搜索树
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
public class Codec {
    private static final String NULL = "#", BETWEEN = ",";

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null)  return NULL;
        StringBuilder sb = new StringBuilder();
        preorder(root, sb);
        sb.setLength(sb.length() - 1);
        return sb.toString();
    }

    private void preorder(TreeNode node, StringBuilder sb) {
        if (node != null) {
            sb.append(node.val).append(BETWEEN);
            preorder(node.left, sb);
            preorder(node.right, sb);
        } else {
            sb.append(NULL).append(BETWEEN);
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0)  return null;
        Queue<String> q = new ArrayDeque<>();
        for (String num : data.split(BETWEEN)) {
            q.add(num);
        }
        return builder(q);
    }

    private TreeNode builder(Queue<String> q) {
        String num = q.poll();
        if (num.equals(NULL))  return null;
        TreeNode node = new TreeNode(Integer.parseInt(num));
        node.left = builder(q);
        node.right = builder(q);
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
// @lc code=end

