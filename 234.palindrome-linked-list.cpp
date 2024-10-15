/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* cur = head; 
        ListNode* rev = nullptr;
        
        // Reverse the first half
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* tmp = rev;
            rev = cur;
            cur = cur->next;
            rev->next = tmp;
        }

        // Odd/even number of nodes
        ListNode* tail = fast != nullptr ? cur->next : cur;

        // Check values and undo reversing
        bool ans = true;
        while (rev != nullptr) {
            ans &= rev->val == tail->val;
            if (!ans) {
                // if restoring is not necessary, return early
                return false;
            }

            ListNode* tmp = cur;
            cur = rev;
            rev = rev->next;
            cur->next = tmp;

            tail = tail->next;
        }
        return ans;
    }
};
// @lc code=end

