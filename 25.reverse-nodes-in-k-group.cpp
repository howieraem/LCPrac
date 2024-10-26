/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    static ListNode* reverse(ListNode *head) {
        ListNode* pre = nullptr; 
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

public:
    // T: O(n)
    // S: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* pre = dummy; 
        ListNode* end = dummy;
        while (end != nullptr) {
            for (int i = 0; i < k; ++i) {
                end = end->next;

                // keep order if last step is less than k
                if (end == nullptr) { 
                    return dummy->next;
                }
            }

            // Disconnect, reverse and re-connect
            ListNode* start = pre->next; 
            ListNode* tmp = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = tmp;

            // Prepare for next round of reversing k nodes
            pre = end = start;
        }
        return dummy->next;
    }
};
// @lc code=end

