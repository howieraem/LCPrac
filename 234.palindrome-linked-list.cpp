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
        ListNode *fast = head, *rev = nullptr;
        
        // Reverse the first half
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode *tmp = rev;
            rev = head;
            head = head->next;
            rev->next = tmp;
        }

        // Odd/even number of nodes
        ListNode *tail = fast ? head->next : head;

        // Check values and undo reversing
        bool ans = true;
        while (rev) {
            ans &= rev->val == tail->val;
            ListNode *tmp = head;
            head = rev;
            rev = rev->next;
            head->next = tmp;
            tail = tail->next;
        }
        return ans;
    }
};
// @lc code=end

