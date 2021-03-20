/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        boolean carry = false;
        while (l1 != null || l2 != null) {
            int v1 = l1 == null ? 0 : l1.val;
            int v2 = l2 == null ? 0 : l2.val;
            int sum = v1 + v2 + (carry ? 1 : 0);
            carry = sum >= 10;
            cur.next = new ListNode(sum % 10);
            if (l1 != null)  l1 = l1.next;
            if (l2 != null)  l2 = l2.next;
            cur = cur.next;
        }
        if (carry)  cur.next = new ListNode(1);
        return dummy.next;
    }
}
// @lc code=end

