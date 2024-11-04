/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
#include <bits/stdc++.h>

using std::stack;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // use stack to reduce duplicate traversal for main branch nodes
    // T: O(n)
    // S: O(n)
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node* pre = nullptr;
        Node* cur = head;
        stack<Node*> tmp_nxt_nodes;

        while (cur != nullptr) {
            if (cur->child != nullptr) {
                tmp_nxt_nodes.push(cur->next);
                cur->child->prev = cur;
                cur->next = cur->child;
                cur->child = nullptr;
            }
            pre = cur;
            cur = cur->next;
        }

        cur = pre;
        while (!tmp_nxt_nodes.empty()) {
            Node* tmp = tmp_nxt_nodes.top();
            cur->next = tmp;
            if (tmp != nullptr) {
                tmp->prev = cur; 
            }
            tmp_nxt_nodes.pop();
            while (cur->next != nullptr) {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

