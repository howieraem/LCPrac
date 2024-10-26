/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    // Fast slow pointers
    // T: O(n)
    // S: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 0) {
            return head;
        }

        // Get list length
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->next;
        }

        k %= n;  // avoid unnecessary rotations
        if (k == 0) {
            return head;
        }

        // Move pointers to target locations
        ListNode* fast = head;
        while (k-- > 0) {
            fast = fast->next;
        }
        ListNode* slow = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Break, rotate and reconnect
        ListNode* new_head = slow->next;
        slow->next = nullptr;

        cur = new_head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = head;

        return new_head;
    }
};
// @lc code=end

