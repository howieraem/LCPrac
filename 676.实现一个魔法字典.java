/*
 * @lc app=leetcode.cn id=676 lang=java
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
class TrieNode {
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


class MagicDictionary {
    private TrieNode root;

    /** Initialize your data structure here. */
    public MagicDictionary() {
        root = new TrieNode();
    }
    
    public void buildDict(String[] dictionary) {
        for (String w : dictionary) {
            insert(w);
        }
    }
    
    public boolean search(String searchWord) {
        return searchHelper(root, searchWord.toCharArray(), 0, false);
    }

    private void insert(String word) {
        TrieNode tmp = root;
        for (char chr : word.toCharArray()) {
            int chrIdx = chr - 'a';
            if (tmp.get(chrIdx) == null) {
                tmp.put(chrIdx, new TrieNode());
            }
            tmp = tmp.get(chrIdx);
        }
        tmp.setEnd();
    }

    private static boolean searchHelper(TrieNode node, char[] word, int idx, boolean replaced) {
        if (node == null)  return false;
        if (word.length == idx)  return replaced && node.isEnd();
        for (int i = 0; i < 26; ++i) {
            if (node.get(i) != null) {
                if (word[idx] - 'a' == i) {
                    if (searchHelper(node.get(i), word, idx + 1, replaced))  return true;
                } else if (!replaced && searchHelper(node.get(i), word, idx + 1, true)) {
                    // do replacement
                    return true;
                }
            }
        }
        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
// @lc code=end

