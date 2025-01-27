/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Linked list
    // T: O(1)
    // S: O(1)
    void deleteNode(ListNode* node) {
        // Since we have no access to the previous node, we
        // will copy the value and the next pointer of the next 
        // node to this node, and then delete the next node
        if (node != nullptr) {
            ListNode* next = node->next;
            node->val = next->val;
            node->next = next->next;
            delete next;
        }
    }
};
// @lc code=end

