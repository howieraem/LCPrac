/*
 * @lc app=leetcode.cn id=328 lang=java
 *
 * [328] 奇偶链表
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
    public ListNode oddEvenList(ListNode head) {
        if (head == null)  return null;
        ListNode even = new ListNode(-1), odd = head;
        ListNode evenHead = even;
        while (odd.next != null) {
            ListNode nxt = odd.next;
            even.next = nxt;
            odd.next = nxt.next;
            nxt.next = null;
            if (odd.next == null)  break;

            odd = odd.next;
            even = even.next;
        }
        odd.next = evenHead.next;
        return head;
    }
}
// @lc code=end

