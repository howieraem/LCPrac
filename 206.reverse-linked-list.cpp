/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    // Linked list + two pointers
    // T: O(n)
    // S: O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr; 
        ListNode* cur = head;
        while (cur != nullptr) {
            // cur's next connect to pre instead
            ListNode* tmp = cur->next;
            cur->next = pre;

            // shift pointers
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

