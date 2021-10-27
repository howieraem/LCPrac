/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *head, *pre;

    Node* treeToDoublyList(Node* root) {
        if (!root)  return nullptr;
        inorder(root);
        // Don't forget to connect head and tail
        head->left = pre;
        pre->right = head;
        return head;
    }

    void inorder(Node* cur) {
        if (!cur)  return;
        inorder(cur->left);
        if (pre) {
            pre->right = cur;
            cur->left = pre;
        } else {
            // Node with the smallest value in the BST
            head = cur;
        }
        pre = cur;
        inorder(cur->right);
    }
};
// @lc code=end

