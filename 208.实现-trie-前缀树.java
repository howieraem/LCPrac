/*
 * @lc app=leetcode.cn id=208 lang=java
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
    private TrieNode root;

    private class TrieNode {
        private TrieNode[] children;
        private boolean isEnd;

        public TrieNode() {
            children = new TrieNode[26];
            isEnd = false;
        }

        public TrieNode get(int idx) {
            return children[idx];
        }

        public void put(int idx, TrieNode node) {
            children[idx] = node;
        }

        public boolean isEnd() {
            return isEnd;
        }

        public void setEnd() {
            isEnd = true;
        }
    }

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode tmp = root;
        // for (char chr: word.toCharArray()) {
        for (int i = 0; i < word.length(); ++i) {
            char chr = word.charAt(i);
            int chrIdx = chr - 'a';
            if (tmp.get(chrIdx) == null) {
                tmp.put(chrIdx, new TrieNode());
            }
            tmp = tmp.get(chrIdx);
        }
        tmp.setEnd();
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode tmp = root;
        for (int i = 0; i < word.length(); ++i) {
            char cur = word.charAt(i);
            int chrIdx = cur - 'a';
            if (tmp.get(chrIdx) != null) {
                tmp = tmp.get(chrIdx);
            } else {
                return false;
            }
        }
        return tmp.isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode tmp = root;
        for (int i = 0; i < prefix.length(); ++i) {
            char cur = prefix.charAt(i);
            int chrIdx = cur - 'a';
            if (tmp.get(chrIdx) != null) {
                tmp = tmp.get(chrIdx);
            } else {
                return false;
            }
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
// @lc code=end

