/*
 * @lc app=leetcode.cn id=677 lang=java
 *
 * [677] 键值映射
 */

// @lc code=start
class TrieNode {
    TrieNode[] next;
    int val, sum;

    public TrieNode() {
        next = new TrieNode[26];
        val = 0;
        sum = 0;
    }
}

class MapSum {
    private TrieNode root;

    /** Initialize your data structure here. */
    public MapSum() {
        root = new TrieNode();
    }
    
    public void insert(String key, int val) {
        TrieNode node = root;
        char[] a = key.toCharArray();
        val -= get(a);
        for (char c : a) {
            node.sum += val;
            int i = c - 'a';
            if (node.next[i] == null) {
                node.next[i] = new TrieNode();
            }
            node = node.next[i];
        }
        node.val += val;
        node.sum += val;
    }
    
    public int sum(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            node = node.next[c - 'a'];
            if (node == null)  return 0;
        }
        return node.sum;
    }

    private int get(char[] a) {
        TrieNode node = root;
        for (char c : a) {
            int i = c - 'a';
            if (node.next[i] == null)  return 0;
            node = node.next[i];
        }
        return node.val;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
// @lc code=end

