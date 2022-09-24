/*
 * @lc app=leetcode id=297 lang=java
 *
 * [297] Serialize and Deserialize Binary Tree
 */
import java.util.*;

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
    private static final String NULL_NODE_STR = "X", SEPARATOR = ",";

    // Encodes a tree to a single string.
    // T: O(n)
    // S: O(n) recursion stack worst case
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        buildString(root, sb);
        return sb.toString();
    }

    // Pre-order traversal
    // T: O(n)
    // S: O(n) recursion stack worst case
    private void buildString(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append(NULL_NODE_STR);
        } else {
            sb.append(node.val).append(SEPARATOR);
            buildString(node.left, sb);
            sb.append(SEPARATOR);  // IMPORTANT
            buildString(node.right, sb);
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<String> q = new ArrayDeque<>(Arrays.asList(data.split(SEPARATOR)));
        return buildTree(q);
    }

    private TreeNode buildTree(Queue<String> q) {
        String val = q.poll();
        if (val.equals(NULL_NODE_STR)) return null;
        TreeNode root = new TreeNode(Integer.valueOf(val));
        root.left = buildTree(q);
        root.right = buildTree(q);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
// @lc code=end

