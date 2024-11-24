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
    
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
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
    // Linked list + two pointers
    // T: O(n)
    // S: O(1) (not considering the output list)
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        // For each node, clone it and put the cloned node after
        Node* cur = head;
        while (cur != nullptr) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;

            cur = copy->next;
        }

        // Copy the random connections
        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                // copy->random = (cur->random)'s copy
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // Disconnect the node copies and construct the list copy
        cur = head;
        Node* copy = cur->next, *head_new = copy;
        while (cur != nullptr) {
            cur->next = cur->next->next;

            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            cur = cur->next;
            copy = copy->next;
        }
        return head_new;
    }
};
// @lc code=end

