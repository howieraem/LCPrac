/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
    // T: O(len(list2) + b)
    // S: O(1)
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if (b > a) {
            return list1;
        }

        ListNode* start = list1, *end = list1;
        while (a-- > 1 && start != nullptr) {
            start = start->next;
        }
        if (start == nullptr) {
            return list1;
        }

        while (b-- > 0 && end != nullptr) {
            end = end->next;
        }

        // Connect head of list2
        start->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }

        // Connect tail of list2 back to list1
        list2->next = end != nullptr ? end->next : nullptr;
        
        return list1;
    }
};
// @lc code=end

