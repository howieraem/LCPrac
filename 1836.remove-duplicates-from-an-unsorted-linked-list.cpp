/*
 * @lc app=leetcode id=1836 lang=cpp
 *
 * [1836] Remove Duplicates From an Unsorted Linked List
 */
#include <unordered_map>

using std::unordered_map;

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
    // S: O(n)
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if (!head || !head->next)  return head;
        unordered_map<int, int> freq;
        ListNode *cur = head;
        while (cur) {
            ++freq[cur->val];
            cur = cur->next;
        }

        ListNode *dummy = new ListNode(0, head), *pre = dummy;
        cur = head;
        while (cur) {
            if (freq[cur->val] > 1) {
                pre->next = cur->next;
                cur->next = nullptr;

                // Make sure `cur` points to the previous node as the current node has been removed
                cur = pre; 
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end

