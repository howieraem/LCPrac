import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.Set;
import java.util.HashMap;
import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=863 lang=java
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    private Map<TreeNode, TreeNode> parents;
    private Set<TreeNode> visited;
    private List<Integer> res;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        parents = new HashMap<>();
        visited = new HashSet<>();
        res = new ArrayList<>();

        findParents(root, null);
        // Assuming `target` has already been pointed to the actual node and
        // thus no need to find it by target value
        dfs(target, k);     
        return res;
    }

    private void findParents(TreeNode root, TreeNode parent) {
        if (root == null)  return;
        parents.put(root, parent);
        findParents(root.left, root);
        findParents(root.right, root);
    }

    private void dfs(TreeNode root, int distToTarget) {
        if (root == null || visited.contains(root))  return;
        visited.add(root);
        if (distToTarget == 0) {
            res.add(root.val);
            return;
        }

        --distToTarget;
        dfs(root.left, distToTarget);
        dfs(root.right, distToTarget);
        dfs(parents.get(root), distToTarget);
    }
}
// @lc code=end

