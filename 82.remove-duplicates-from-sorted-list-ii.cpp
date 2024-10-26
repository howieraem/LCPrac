/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    // Fast slow pointers
    // T: O(n)
    // S: O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            // skip duplicates
            while (cur->next != nullptr && cur->val == cur->next->val) {
                cur = cur->next;
            }

            if (pre->next == cur) {
                pre = pre->next;
            } else {
                // remove duplicates
                pre->next = cur->next;
            }

            cur = cur->next;
        }

        return dummy->next;
    }
};
// @lc code=end

