/*
 * @lc app=leetcode id=652 lang=java
 *
 * [652] Find Duplicate Subtrees
 */
import java.util.*;

public class TreeNode {
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
    private int curId;

    // T: O(n)
    // S: O(n)
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        curId = 1;
        Map<String, Integer> serialId = new HashMap<>(); 
        Map<Integer, Integer> idCnt = new HashMap<>();
        List<TreeNode> res = new ArrayList<>();
        traverse(root, serialId, idCnt, res);
        return res;
    }

    private int traverse(TreeNode node, Map<String, Integer> serialId, Map<Integer, Integer> idCnt, List<TreeNode> res) {
        if (node == null) return 0;
        int left = traverse(node.left, serialId, idCnt, res),
            right = traverse(node.right, serialId, idCnt, res);
        String s = left + "," + node.val + "," + right; // this is O(1), faster than the full serialization of the subtree
        int sid;
        if (serialId.containsKey(s)) {
            sid = serialId.get(s);
        } else {
            sid = ++curId;
            serialId.put(s, sid);
        }
        idCnt.put(sid, idCnt.getOrDefault(sid, 0) + 1);
        if (idCnt.get(sid) == 2) res.add(node);
        return sid;
    }
}
// @lc code=end

