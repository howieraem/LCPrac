/*
 * @lc app=leetcode.cn id=143 lang=java
 *
 * [143] 重排链表
 */

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

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
    public void reorderList(ListNode head) {
        /**
         * 1. Split linked list in halves
         * 2. Reverse the second half
         * 3. Alternate the first half nodes and the reversed second half nodes
         * 
         * Example:
         * [1,2,3,4] -> [1,2], [3,4] -> [1,2], [4,3] -> [1,4,2,3]
         */
        if (head == null || head.next == null || head.next.next == null)  return;
        /** Find mid point and split */
        ListNode slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode headOfLatterHalf = slow.next;
        slow.next = null;

        /** Reverse the latter half */
        headOfLatterHalf = reverseList(headOfLatterHalf);

        /** Merge half lists */
        while (headOfLatterHalf != null) {
            ListNode tmp = headOfLatterHalf.next;
            headOfLatterHalf.next = head.next;
            head.next = headOfLatterHalf;
            head = headOfLatterHalf.next;
            headOfLatterHalf = tmp;
        }
    }

    private ListNode reverseList(ListNode head) {
        ListNode pre = null, cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
// @lc code=end

