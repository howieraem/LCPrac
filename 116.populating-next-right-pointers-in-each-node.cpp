/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
#include <queue>

using std::queue;

struct Node {
    int val;
    Node *left, *right, *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /*
    // Iterative solution with an auxiliary queue
    // T: O(n), n := the number of nodes
    // S: O(n)
    Node* connect(Node* root) {
        if (root == nullptr)  return nullptr;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int qs = q.size();
            while (qs-- > 0) {
                Node *node = q.front(); q.pop();
                if (qs > 0) {
                    node->next = q.front();
                }
                if (node->left) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return root;
    }
    */

    // Iterative solution without extra space
    // T: O(n), n := the number of nodes
    // S: O(1)
    Node* connect(Node* root) {
        Node* pre = root;
        while (pre != nullptr) {
            Node* cur = pre;
            while (cur != nullptr) {
                // Connects the left child to the right child
                if (cur->left) {
                    cur->left->next = cur->right;
                }
                // Connects the right child to the left child of 
                // the sibling node
                if (cur->right && cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }
};
// @lc code=end

