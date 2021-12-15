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
    // T: O(k*log(k)*n), k := the number of lists, n := avg. length of list
    // S: O(1)? (C/C++ tail recursion)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partition(lists, 0, lists.size() - 1);
    }

private:
    static ListNode* partition(vector<ListNode*>& lists, int l, int r) {
        if (l == r)  return lists[l];   // the number of linked lists is odd
        else if (l > r)  return nullptr;
        else {
            int m = l + ((r - l) >> 1);
            ListNode* l1 = partition(lists, l, m);
            ListNode* l2 = partition(lists, m + 1, r);
            return merge(l1, l2);
        }
    }

    // Recursively merges two lists, avoids creating a dummy node
    static ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1)  return l2;
        if (!l2)  return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end

