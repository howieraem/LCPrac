/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */
#include <vector>

using namespace std;

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }

        vector<ListNode*> res(k, nullptr);
        int r = n % k, a = n / k;
        cur = head; 
        ListNode* pre = nullptr;

        // Since res is filled with null,
        // add `cur != null` in loop condition
        // to stop early. Meanwhile, r could
        // be decremented in each loop.
        for (int i = 0; cur && i < k; ++i, --r) {
            res[i] = cur;
            // Add 1 to a if r > 0
            for (int j = 0; j < a + (r > 0); ++j) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = nullptr;
        }
        return res;
    }
};
// @lc code=end

