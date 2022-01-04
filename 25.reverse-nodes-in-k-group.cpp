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
        ListNode *pre = nullptr, *cur = head, *tmp;
        while (cur) {
            tmp = cur->next;
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
        ListNode *dummy = new ListNode(0, head);

        ListNode *pre = dummy, *start, *end = dummy, *tmp;
        while (end) {
            for (int i = 0; i < k; ++i) {
                end = end->next;

                // keep order if last step is less than k
                if (!end)  return dummy->next;
            }

            // Disconnect, reverse and re-connect
            start = pre->next; 
            tmp = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = tmp;

            pre = end = start;
        }
        return dummy->next;
    }
};
// @lc code=end

