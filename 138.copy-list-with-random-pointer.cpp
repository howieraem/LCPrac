/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // T: O(n)
    // S: O(1) (not considering the output list)
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        // For each node, clone it and put the cloned node after
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;

            cur = copy->next;
        }

        // Copy the random connections
        cur = head;
        while (cur) {
            if (cur->random) {
                // copy->random = cur->random 's copy
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // Disconnect the node copies and construct the list copy
        cur = head;
        Node* copy = cur->next, *head_new = copy;
        while (cur) {
            cur->next = cur->next->next;

            if (copy->next) {
                copy->next = copy->next->next;
            }

            cur = cur->next;
            copy = copy->next;
        }
        return head_new;
    }
};
// @lc code=end

