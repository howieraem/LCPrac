/*
 * @lc app=leetcode.cn id=147 lang=java
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null)  return head;
        ListNode dummy = new ListNode(Integer.MIN_VALUE), pre = head, cur = head.next;
        dummy.next = head;
        while (cur != null) {
            if (cur.val < pre.val) {
                ListNode tmp = dummy;
                while (tmp.next.val < cur.val) {
                    tmp = tmp.next;
                }
                pre.next = cur.next;
                cur.next = tmp.next;
                tmp.next = cur;
                cur = pre.next;
            } else {
                pre = pre.next;
                cur = cur.next;
            }
        }
        return dummy.next;
    }
}
// @lc code=end

