/*
 * @lc app=leetcode.cn id=82 lang=java
 *
 * [82] 删除排序链表中的重复元素 II
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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)  return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        ListNode slow = dummy, fast = dummy.next;
        while (fast != null) {
            if (fast.next != null && fast.val == fast.next.val) {
                int tmp = fast.val;
                while (fast != null && tmp == fast.val) {
                    fast = fast.next;
                }
            } else {
                slow.next = fast;
                slow = fast;
                fast = fast.next;
            }
        }
        slow.next = fast;   // don't forget the last one
        return dummy.next;
    }
}
// @lc code=end

