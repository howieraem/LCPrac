/*
 * @lc app=leetcode.cn id=445 lang=java
 *
 * [445] 两数相加 II
 */
import java.util.Stack;

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<>(), s2 = new Stack<>();
        while (l1 != null) {
            s1.push(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            s2.push(l2.val);
            l2 = l2.next;
        }

        int carry = 0;
        ListNode head = null;
        // build the new list reversely
        while (!s1.isEmpty() || !s2.isEmpty() || carry > 0) {
            int sum = carry;
            sum += s1.isEmpty() ? 0 : s1.pop();
            sum += s2.isEmpty() ? 0 : s2.pop();
            ListNode node = new ListNode(sum % 10);
            carry = sum / 10;
            node.next = head;
            head = node;
        }
        return head;
    }
}
// @lc code=end

