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
    // BFS level order traversal
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
                    // except the last node of the level
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
        Node* cur = root;

        Node* dummy = new Node();  // pre-head of a level
        Node* p = dummy;

        while (cur != nullptr) {
            if (cur->left != nullptr) {
                p->next = cur->left;   // populate next pointer
                p = p->next;   // move right on the same level
            }
            if (cur->right != nullptr) {
                p->next = cur->right;  // populate next pointer
                p = p->next;   // move right on the same level
            }
            
            if (cur->next != nullptr) {
                cur = cur->next;  // move right on the same level
            } else {
                cur = dummy->next;   // change to pre-head of next level
                
                // begin a new level
                dummy->next = nullptr;
                p = dummy;
            }
        }
        return root;
    }
};
// @lc code=end

