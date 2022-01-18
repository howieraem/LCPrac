import java.util.*;
/*
 * @lc app=leetcode.cn id=589 lang=java
 *
 * [589] N 叉树的前序遍历
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
    // public List<Integer> preorder(Node root) {
    //     List<Integer> res = new ArrayList<>();
    //     helper(root, res);
    //     return res;
    // }

    // private void helper(Node root, List<Integer> res) {
    //     if (root != null) {
    //         res.add(root.val);
    //         for (Node node : root.children) {
    //             helper(node, res);
    //         }
    //     }
    // }

    public List<Integer> preorder(Node root) {
        List<Integer> res = new ArrayList<>();
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while (!stack.empty()) {
            Node node = stack.pop();
            if (node != null) {
                res.add(node.val);
                for (int i = node.children.size() - 1; i >= 0; --i) {
                    stack.push(node.children.get(i));
                }
            }
        }
        return res;
    }
}
// @lc code=end

