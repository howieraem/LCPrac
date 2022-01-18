import java.util.*;
/*
 * @lc app=leetcode.cn id=1019 lang=java
 *
 * [1019] 链表中的下一个更大节点
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
    // public int[] nextLargerNodes(ListNode head) {
    //     Stack<Integer> stack = new Stack<>();
    //     List<Integer> arr = new ArrayList<>();
    //     ListNode node = head; 
    //     while (node != null) {
    //         arr.add(node.val);
    //         node = node.next;
    //     }

    //     final int n = arr.size();
    //     int[] res = new int[n];
    //     for (int i = n - 1; i >= 0; --i) {
    //         while (!stack.empty() && stack.peek() <= arr.get(i)) {
    //             stack.pop();
    //         }
    //         // res[i] = stack.empty() ? 0 : stack.peek();
    //         if (!stack.empty()) {
    //             res[i] = stack.peek();
    //         }
    //         stack.push(arr.get(i));
    //     }
    //     return res;
    // }

    public int[] nextLargerNodes(ListNode head) {
        Stack<Integer> stack = new Stack<>();

        // Reverse the linked list and find its length
        int n = 0;
        ListNode pre = null, tmp;
        while (head != null) {
            tmp = head.next;
            head.next = pre;
            pre = head;
            head = tmp;
            ++n;
        }

        ListNode node = pre;
        int i = n - 1;
        int[] res = new int[n];
        while (node != null) {
            while (!stack.empty() && stack.peek() <= node.val) {
                stack.pop();
            }
            // res[i--] = stack.empty() ? 0 : stack.peek();
            if (!stack.empty()) {
                res[i] = stack.peek();
            }
            --i;
            stack.push(node.val);
            node = node.next;
        }
        return res;
    }
}
// @lc code=end

