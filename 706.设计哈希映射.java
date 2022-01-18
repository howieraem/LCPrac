/*
 * @lc app=leetcode.cn id=706 lang=java
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap {
    private static class Node {
        public int key;
        public int value;
        public Node next;

        public Node(int k, int v) {
            key = k;
            value = v;
            next = null;
        }
    }

    private Node[] data;
    private static final int SZ = 1000;     // at most 10000 operations, so around 10 nodes per bucket

    /** Initialize your data structure here. */
    public MyHashMap() {
        data = new Node[SZ];
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        int i = hash(key);
        if (data[i] == null) {
            data[i] = new Node(key, value);
            return;
        }
        Node cur = data[i];
        while (cur.next != null) {
            if (cur.key == key) {
                cur.value = value;
                return;
            }
            cur = cur.next;
        }
        if (cur.key == key) {
            cur.value = value;
        } else {
            cur.next = new Node(key, value);
        }
    }
    
    public int get(int key) {
        Node cur = data[hash(key)];
        while (cur != null) {
            if (cur.key == key)  return cur.value;
            cur = cur.next;
        }
        return -1;
    }

    public void remove(int key) {
        int i = hash(key);
        Node pre = null, cur = data[i];
        while (cur != null) {
            if (cur.key == key) {
                if (pre == null) {
                    data[i] = data[i].next;
                } else {
                    pre.next = cur.next;
                }
                return;
            } else {
                pre = cur;
                cur = cur.next;
            }
        }
    }

    private int hash(int key) {
        return key % SZ;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
// @lc code=end

