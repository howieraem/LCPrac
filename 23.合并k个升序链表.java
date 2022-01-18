/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并K个升序链表
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
    public ListNode mergeKLists(ListNode[] lists) {
        return helper(lists, 0, lists.length - 1);
    }

    private ListNode helper(ListNode[] lists, int l, int r) {
        // divide and conquer: merge lists two-by-two
        if (l == r)  return lists[l];
        else if (l > r)  return null;
        int mid = l + (r - l) / 2;
        return merge2Lists(helper(lists, l, mid), helper(lists, mid + 1, r));
    }

    private ListNode merge2Lists(ListNode a, ListNode b) {
        // O(N)
        if (a == null || b == null)  return a != null ? a : b;
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy, curA = a, curB = b;
        while (curA != null && curB != null) {
            if (curA.val < curB.val) {
                cur.next = curA;
                curA = curA.next;
            } else {
                cur.next = curB;
                curB = curB.next;
            }
            cur = cur.next;
        }
        cur.next = curA != null ? curA : curB;
        return dummy.next;
    }
}
// @lc code=end

