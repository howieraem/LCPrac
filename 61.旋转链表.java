/*
 * @lc app=leetcode.cn id=61 lang=java
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k <= 0)  return head;
        
        int n = 0;
        ListNode node = head;
        while (node != null) {
            ++n;
            node = node.next;
        }
        k %= n;
        if (k == 0)  return head;

        ListNode fast = head, slow = head;
        for (int i = 0; i < k; ++i) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }

        ListNode newHead = slow.next;
        slow.next = null;
        node = newHead;
        while (node.next != null) {
            node = node.next;
        }
        node.next = head;
        return newHead;
    }
}
// @lc code=end

