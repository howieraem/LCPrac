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
    // T: O(n)
    // S: O(1)
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Get linked list length
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->next;
        }

        vector<ListNode*> res(k, nullptr);
        int base_part_len = n / k;
        int extra_part_len = n % k;
        cur = head; 
        ListNode* pre = nullptr;

        // Since res is filled with null,
        // add `cur != null` in loop condition to
        // stop early. Meanwhile, r is decremented 
        // in each iteration (1 additional element
        // appended to the first few parts).
        for (int i = 0; cur != nullptr && i < k; ++i) {
            res[i] = cur;
            // Add 1 to a if r > 0
            for (int j = 0; j < base_part_len + (extra_part_len > 0); ++j) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = nullptr;  // split at each part's tail
            --extra_part_len;
        }
        return res;
    }
};
// @lc code=end

