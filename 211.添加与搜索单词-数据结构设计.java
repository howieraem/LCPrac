/*
 * @lc app=leetcode.cn id=211 lang=java
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start

// Using code from q208.
class WordDictionary {
    private TrieNode root;

    private class TrieNode {
        TrieNode[] children;
        boolean isEnd;

        public TrieNode() {
            children = new TrieNode[26];
            isEnd = false;
        }
    }

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        char[] arr = word.toCharArray();
        TrieNode cur = root;
        for (int i = 0; i < arr.length; ++i) {
            int cIdx = arr[i] - 'a';
            if (cur.children[cIdx] == null) {
                cur.children[cIdx] = new TrieNode();
            }
            cur = cur.children[cIdx];
        }
        cur.isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return helper(word, root);
    }

    private static boolean helper(String word, TrieNode root) {
        char[] arr = word.toCharArray();
        TrieNode cur = root;
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (cur.children[j] != null && helper(word.substring(i + 1), cur.children[j])) {
                        return true;
                    }
                }
                return false;
            }
            int cIdx = arr[i] - 'a';
            if (cur.children[cIdx] == null) {
                return false;
            }
            cur = cur.children[cIdx];
        }
        return cur.isEnd;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
// @lc code=end

