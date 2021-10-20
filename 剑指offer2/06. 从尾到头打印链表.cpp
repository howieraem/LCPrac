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
    /*
    // Recursive solution, faster but more memory
    vector<int> reversePrint(ListNode* head) {
        if (!head)  return {};
        vector<int> res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
    */

    vector<int> reversePrint(ListNode* head) {
        if (!head)  return {};
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};