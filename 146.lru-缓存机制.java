// import java.util.HashMap;
import java.util.LinkedHashMap;

/*
 * @lc app=leetcode.cn id=146 lang=java
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
/*
class Node {
    public int k, v;
    public Node pre, nxt;
    public Node(int k, int v) {
        this.k = k;
        this.v = v;
    }
}

class DoublyLinkedList {
    private Node head, tail;
    private int sz;

    public DoublyLinkedList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.nxt = tail;
        tail.pre = head;
        sz = 0;
    }

    public void addLast(Node x) {
        x.pre = tail.pre;
        x.nxt = tail;
        tail.pre.nxt = x;
        tail.pre = x;
        ++sz;
    }

    public void remove(Node x) {
        x.pre.nxt = x.nxt;
        x.nxt.pre = x.pre;
        --sz;
    }

    public Node removeFirst() {
        if (head.nxt == tail)  return null;
        Node first = head.nxt;
        remove(first);
        return first;
    }

    public int size() {
        return sz;
    }
}

class LRUCache {
    private HashMap<Integer, Node> map;
    // List head is least recent, tail is most recent
    private DoublyLinkedList cache;
    private int cap;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        cache = new DoublyLinkedList();
        cap = capacity;
    }
    
    public int get(int key) {
        if (!map.containsKey(key))  return -1;
        makeRecent(key);
        return map.get(key).v;
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            delKey(key);
            addRecent(key, value);
            return;
        }
        if (cap == cache.size()) {
            removeLeastRecent();
        }
        addRecent(key, value);
    }

    private void makeRecent(int key) {
        Node x = map.get(key);
        cache.remove(x);
        cache.addLast(x);
    }

    private void addRecent(int key, int value) {
        Node x = new Node(key, value);
        map.put(key, x);
        cache.addLast(x);
    }

    private void delKey(int key) {
        Node x = map.get(key);
        map.remove(key);
        cache.remove(x);
    }

    private void removeLeastRecent() {
        Node deleted = cache.removeFirst();
        map.remove(deleted.k);
    }
}
*/

class LRUCache {
    LinkedHashMap<Integer, Integer> cache;
    int cap;

    public LRUCache(int capacity) {
        cache = new LinkedHashMap<>();
        cap = capacity;
    }

    public int get(int key) {
        if (!cache.containsKey(key))  return -1;
        makeRecent(key);
        return cache.get(key);
    }
    
    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            cache.put(key, value);
            makeRecent(key);
            return;
        }
        if (cache.size() >= cap) {
            int oldest = cache.keySet().iterator().next();
            cache.remove(oldest);
        }
        cache.put(key, value);
    }

    /** Ensures the key is the first one in the key set of hashmap. */
    private void makeRecent(int key) {
        int value = cache.get(key);
        cache.remove(key);
        cache.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end

