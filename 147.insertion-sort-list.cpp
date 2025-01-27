/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */
#include <bits/stdc++.h>

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
    // Linkedin List + two pointers
    // T: O(n)
    // S: O(1)
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(INT_MIN); 
        ListNode* cur = head;
        ListNode* pre = dummy;
        ListNode* tmp = nullptr;

        while (cur != nullptr) {
            tmp = cur->next;

            // Find the correct place to (re)insert
            while (pre->next != nullptr && pre->next->val < cur->val) {
                pre = pre->next;
            }

            // Insert between pre and pre->next
            cur->next = pre->next;
            pre->next = cur;

            // Reset pre back to the dummy head, and move cur forward
            pre = dummy;
            cur = tmp;
        }

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};
// @lc code=end

