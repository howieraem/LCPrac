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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *cur = head, *pre;
        if (cur->val == val)  return head->next;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur->next = nullptr;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};