/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // T: O(n)
    // S: O(1)
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode();
        ListNode* dummy2 = new ListNode();
        
        // Create two separate lists based on partition value
        ListNode* p1 = dummy1;
        ListNode* p2 = dummy2;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                // For node values < x
                p1->next = cur;
                p1 = p1->next;
            } else {
                // For node values >= x
                p2->next = cur;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        // Link the two lists
        p2->next = nullptr;
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
// @lc code=end

