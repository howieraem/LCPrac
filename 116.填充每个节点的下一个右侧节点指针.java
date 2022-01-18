/*
 * @lc app=leetcode.cn id=116 lang=java
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if (root == null)  return null;
        connectTwoNodes(root.left, root.right);
        return root;
    }

    private void connectTwoNodes(Node left, Node right) {
        if (left == null || right == null)  return;
        left.next = right;

        // connect left and right children with the same parent
        connectTwoNodes(left.left, left.right);
        connectTwoNodes(right.left, right.right);

        // connect nodes between two subtrees
        connectTwoNodes(left.right, right.left);
    }
}
// @lc code=end

