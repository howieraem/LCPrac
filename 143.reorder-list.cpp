/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    ListNode* reverse_list(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        } 
        return pre;
    }

public:
    // Linked list + two pointers + fast slow pointers
    // Split list in halves, reverse the 2nd half, and merge the 1st half and the reversed 2nd half
    // T: O(n)
    // S: O(1)
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;  // IMPORTANT edge cases
        }

        // Find the midpoint with fast and slow pointers, and split
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head_of_half2 = slow->next;
        slow->next = nullptr;

        // Reverse the tail half
        ListNode* p2 = reverse_list(head_of_half2);

        // Merge
        ListNode* p1 = head;
        while (p2 != nullptr) {
            // Change connections
            ListNode* original_next_p2 = p2->next;
            p2->next = p1->next;
            p1->next = p2;

            // Shift pointers
            p1 = p2->next;   // original next p1
            p2 = original_next_p2;
        }
    }
};
// @lc code=end

