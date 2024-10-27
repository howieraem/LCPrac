/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Fast slow pointers
    // T: O(n)
    // S: O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        do {
            if (!fast || !fast->next)  return nullptr;  // no cycle
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        // Now slow pointer is at the intersection (cycle's entrance) 

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// @lc code=end

