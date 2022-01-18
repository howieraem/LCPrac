/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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
        if (!root)  return nullptr;
        queue<Node*> q;
        q.push(root);

        while (q.size()) {
            const int qs = q.size();
            for (int i = 0; i < qs; ++i) {
                Node *node = q.front(); q.pop();
                if (i < qs - 1) {
                    // except the last node of the layer
                    node->next = q.front();
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
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
        Node *cur = root;
        Node tmp(-1);
        while (cur) {
            Node *pre = &tmp;
            while (cur) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            if (pre != &tmp) {  // level is not empty
                cur = tmp.next;
            }
        }
        return root;
    }
};
// @lc code=end

