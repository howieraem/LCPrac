/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    // Different from normal number addition, the carry is going to the next pair of numbers
    // T: O(max(n1, n2)), n1 := len(l1), n2 := len(l2)
    // S: O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *cur = dummy;
        bool carry = false;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            carry = sum >= 10;
            cur->next = new ListNode(sum % 10);
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }

        while (l1 != nullptr) {
            int sum = l1->val + carry;
            carry = sum >= 10;
            cur->next = new ListNode(sum % 10);
            l1 = l1->next;
            cur = cur->next;
        }

        while (l2 != nullptr) {
            int sum = l2->val + carry;
            carry = sum >= 10;
            cur->next = new ListNode(sum % 10);
            l2 = l2->next;
            cur = cur->next;
        }

        // Don't forget the final carry
        if (carry) {
            cur->next = new ListNode(1);
        }
        return dummy->next;
    }
};
// @lc code=end

