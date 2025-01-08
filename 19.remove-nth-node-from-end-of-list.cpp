/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    // Linked list + Fast slow pointers
    // T: O(n)
    // S: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // return dummy->next at the end, in case the original head gets deleted
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* fast = dummy; 
        ListNode* slow = dummy;
        while (n-- > 0 && fast != nullptr) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            // n is greater than list length
            return head;
        }

        // fast pointer leads slow pointer by n
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // remove node from list
        ListNode* target = slow->next;
        slow->next = slow->next->next;
        delete target;

        head = dummy->next;
        delete dummy;
        return head;
    }
};
// @lc code=end

