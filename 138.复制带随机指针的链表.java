/*
 * @lc app=leetcode.cn id=138 lang=java
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)  return null;
        /**
         * Clone node and place each new node to the right of its original node, 
         * e.g. [1, 2] becomes [1, 1', 2, 2', 3, 3']. 
         */
        Node cur = head;
        while (cur != null) {
            Node newNode = new Node(cur.val);
            newNode.next = cur.next;
            cur.next = newNode;
            cur = newNode.next;
        }

        /** 
         * Now clone the random links.
         * For example, given [1, 1', 2, 2', 3, 3'] from last stage and
         * 1.random = 3, then make 1'.random = 3' here.
         */
        cur = head;
        while (cur != null) {
            if (cur.random != null) {
                cur.next.random = cur.random.next;
            }
            cur = cur.next.next; 
        }

        /**
         * Finally, "decouple" the cloned nodes from original nodes.
         */
        Node curOld = head, curNew = head.next;
        Node headNew = head.next;
        while (curOld != null) {
            // make corresponding links
            curOld.next = curOld.next.next;
            if (curNew.next != null) {
                curNew.next = curNew.next.next;
            }

            // move pointers to their next ones
            curOld = curOld.next;
            curNew = curNew.next;
        }
        return headNew;
    }
}
// @lc code=end

