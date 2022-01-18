import java.util.*;
/*
 * @lc app=leetcode.cn id=501 lang=java
 *
 * [501] 二叉搜索树中的众数
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
    List<Integer> res;
    int pre, cnt, maxCnt;

    public int[] findMode(TreeNode root) {
        res = new ArrayList<>();
        cnt = 0;
        maxCnt = 0;
        inorder(root);

        int n = res.size();
        int[] ress = new int[n];
        for (int i = 0; i < n; ++i) {
            ress[i] = res.get(i);
        }
        return ress;
    }

    private void inorder(TreeNode node) {
        if (node == null)  return;
        inorder(node.left);
        if (node.val == pre) {
            ++cnt;
        } else {
            cnt = 1;
            pre = node.val;
        }
        if (cnt == maxCnt) {
            res.add(node.val);
        } else if (cnt > maxCnt) {
            res.clear();
            res.add(node.val);
            maxCnt = cnt;
        }
        inorder(node.right);
    }
}
// @lc code=end

