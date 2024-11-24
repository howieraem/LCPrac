/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include <vector>

using std::vector;

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
    // Linked list + Divide and conquer + two pointers
    // T: O(n * log(k)), k := the number of lists, n := avg. length of list
    // S: O(log(k)) if using recursive partition, O(1) if using iterative partition
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Recursive partition
        // return partition(lists, 0, lists.size() - 1);

        // Iterative partition
        if (lists.empty()) {
            return nullptr;
        }

        int n = lists.size();
        while (n > 1) {
            for (int l = 0; l < (n >> 1); ++l) {
                int r = n - 1 - l;
                lists[l] = mergeTwoLists(lists[l], lists[r]);
            }
            n = (n + 1) >> 1;
        }
        return lists.front();
    }

private:
    // S: O(log(k))
    static ListNode* partition(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return lists[l];   // the number of linked lists is odd
        } else if (l > r) { 
            return nullptr;
        } else {
            int m = l + ((r - l) >> 1);
            ListNode* l1 = partition(lists, l, m);
            ListNode* l2 = partition(lists, m + 1, r);
            return mergeTwoLists(l1, l2);
        }
    }

    /*
    // Recursively merges two lists (might be faster in some languages), 
    // and avoids creating a dummy node (but recursion stack exists)
    // S: O(n)
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    */
 
    // Iteratively merges two lists, like Q21
    // S: O(1)
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }

        cur->next = cur1 != nullptr ? cur1 : cur2;

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
// @lc code=end

