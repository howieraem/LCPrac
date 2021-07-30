import java.util.*;
/*
 * @lc app=leetcode.cn id=508 lang=java
 *
 * [508] 出现次数最多的子树元素和
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
    int maxFreq;
    private Map<Integer, Integer> freq;

    public int[] findFrequentTreeSum(TreeNode root) {
        if (root == null)  return new int[]{};
        maxFreq = -1;
        freq = new HashMap<>();
        subTreeSum(root);

        List<Integer> res = new ArrayList<>();
        for (Map.Entry<Integer, Integer> e : freq.entrySet()) {
            if (e.getValue() == maxFreq)  res.add(e.getKey());
        }

        int[] ress = new int[res.size()];
        for (int i = 0; i < res.size(); ++i) {
            ress[i] = res.get(i);
        }
        return ress;
    }

    private int subTreeSum(TreeNode node) {
        if (node == null)  return 0;
        int sum = node.val + subTreeSum(node.left) + subTreeSum(node.right);
        int curFreq = freq.getOrDefault(sum, 0) + 1;
        maxFreq = Math.max(maxFreq, curFreq);
        freq.put(sum, curFreq);
        return sum;
    }
}
// @lc code=end

