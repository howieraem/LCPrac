import java.util.*;
/*
 * @lc app=leetcode.cn id=590 lang=java
 *
 * [590] N 叉树的后序遍历
 */

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
    // public List<Integer> postorder(Node root) {
    //     List<Integer> res = new ArrayList<>();
    //     helper(root, res);
    //     return res;
    // }

    // private void helper(Node root, List<Integer> res) {
    //     if (root != null) {
    //         for (Node node : root.children) {
    //             helper(node, res);
    //         }
    //         res.add(root.val);
    //     }
    // }

    public List<Integer> postorder(Node root) {
        List<Integer> res = new ArrayList<>();
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while (!stack.empty()) {
            Node node = stack.pop();
            if (node != null) {
                res.add(node.val);
                stack.addAll(node.children);
            }
        }
        Collections.reverse(res);
        return res;
    }
}
// @lc code=end

