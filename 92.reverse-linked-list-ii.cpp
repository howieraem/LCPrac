/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    // T: O(right)
    // S: O(1)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }
        auto dummy = new ListNode(0, head);
        
        auto pre = dummy;
        auto cur = dummy->next;
        int i = 0;
        while (i < left - 1) {
            pre = cur;
            cur = cur->next;
            ++i;
        }
        auto pre_left = pre;

        // start reversing every pair of nodes between left and right
        while (i < right) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            ++i;
        }

        // final adjustment
        pre_left->next->next = cur;
        pre_left->next = pre;

        return dummy->next;
    }
};
// @lc code=end

