/*
 * @lc app=leetcode.cn id=429 lang=java
 *
 * [429] N 叉树的层序遍历
 */
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.List;
import java.util.Queue;

class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null)  return res;
        Queue<Node> q = new ArrayDeque<>();
        q.add(root);

        while (!q.isEmpty()) {
            List<Integer> lvl = new ArrayList<>();
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node cur = q.poll();

                // Unlike binary tree node where node.left or node.right might be
                // null, all children in list are assumed valid nodes and thus 
                // no need to check null here.
                lvl.add(cur.val);
                q.addAll(cur.children);
            }
            res.add(lvl);
        }
        return res;
    }
}
// @lc code=end

