/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    // Merge sort on linked list
    // T: O(n * log(n))
    // S: O(1)
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Get list length
        int n = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            ++n;
        }

        // Divide and conquer
        // step size: 1, 2, 4, ...
        ListNode* dummy = new ListNode(0, head);
        for (int step = 1; step < n; step <<= 1) {
            ListNode* pre = dummy;
            ListNode* cur = dummy->next;
            while (cur != nullptr) {
                ListNode* l = cur;             // head of left sub linked list with len = step
                ListNode* r = split(l, step);  // head of right sub linked list with len = step
                cur = split(r, step);          // head of linked list after right linked list (rest of linked list not processed)
                pre = merge(l, r, pre);
            }
        }

        return dummy->next;
    }

private:
    // split list at i = n
    ListNode* split(ListNode* head, const int& n) {
        if (head == nullptr) {
            return nullptr;
        }
        for (int i = 1; head->next != nullptr && i < n; ++i) {
            head = head->next;
        }
        ListNode* nxt = head->next;
        head->next = nullptr;
        return nxt;  // return the head of the next list
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode* cur = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != nullptr ? l1 : l2;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        return cur;  // return the list tail (non-null) 
    }
};
// @lc code=end

