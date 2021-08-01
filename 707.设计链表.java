/*
 * @lc app=leetcode.cn id=707 lang=java
 *
 * [707] 设计链表
 */

// @lc code=start
class Node {
    int val;
    Node nxt, pre;
    
    Node(int _val, Node _nxt, Node _pre) {
        val = _val;
        nxt = _nxt;
        pre = _pre;
    }
}

class MyLinkedList {
    Node head, tail;
    int sz;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
        tail = null;
        sz = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        int i = 0;
        Node cur = head;
        while (cur != null) {
            if (i == index) {
                return cur.val;
            }
            cur = cur.nxt;
            ++i;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if (head == null) {
            head = new Node(val, null, null);
            tail = head;
        } else {
            Node cur = new Node(val, head, null);
            head.pre = cur;
            head = cur;
        }
        ++sz;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if (tail == null) {
            tail = new Node(val, null, null);
            head = tail;
        } else {
            Node cur = new Node(val, null, tail);
            tail.nxt = cur;
            tail = cur;
        }
        ++sz;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == sz) {
            addAtTail(val);
            return;
        }

        int i = 0;
        Node pre = null, cur = head;
        while (cur != null) {
            if (i == index) {
                Node node = new Node(val, cur, pre);
                if (pre != null)  pre.nxt = node;
                cur.pre = node;
                ++sz;
                return;
            }
            pre = cur;
            cur = cur.nxt;
            ++i;
        }
    }   
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index == 0) {
            head = head.nxt;
            if (head != null)  head.pre = null;
            --sz;
            return;
        }
        if (index == sz - 1) {
            tail = tail.pre;
            if (tail != null)  tail.nxt = null;
            --sz;
            return;
        }

        int i = 0;
        Node pre = null, cur = head;
        while (cur != null) {
            if (i == index) {
                if (pre != null)  pre.nxt = cur.nxt;
                if (cur.nxt != null)  cur.nxt.pre = pre;
                --sz;
                return;
            }
            pre = cur;
            cur = cur.nxt;
            ++i;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
// @lc code=end

