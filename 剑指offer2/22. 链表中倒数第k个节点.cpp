/**
 * Definition for singly-linked list.
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        while (k--) {
            fast = fast->next;
        }
        ListNode* slow = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
