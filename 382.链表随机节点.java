/*
 * @lc app=leetcode.cn id=382 lang=java
 *
 * [382] 链表随机节点
 */
import java.util.concurrent.ThreadLocalRandom;

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
    private ListNode head;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        int cnt = 0, reserve = 0;
        ListNode cur = head;
        while (cur != null) {
            ++cnt;
            int rand = ThreadLocalRandom.current().nextInt(1, cnt + 1);
            if (rand == cnt) {
                reserve = cur.val;
            }
            cur = cur.next;
        }
        return reserve;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
// @lc code=end

