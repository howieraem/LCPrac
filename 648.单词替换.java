import java.util.*;
/*
 * @lc app=leetcode.cn id=648 lang=java
 *
 * [648] 单词替换
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

    public void setEnd() {
        isEnd = true;
    }

    public boolean isEnd() {
        return isEnd;
    }
}

class Solution {
    private TrieNode root;

    public String replaceWords(List<String> dictionary, String sentence) {
        root = new TrieNode();
        dictionary.forEach(p -> insert(p));

        int n = sentence.length(), i = 0;
        StringBuilder sb = new StringBuilder(n);
        char[] a = sentence.toCharArray();
        TrieNode node = root;
        while (i < n) {
            char c = a[i];
            if (c == ' ') {
                node = root;
                sb.append(' ');
                ++i;
                continue;
            }
            sb.append(c);
            if (node != null) {
                node = node.get(c - 'a');
            }
            if (node != null && node.isEnd()) {
                // found a prefix, skip the remaining chars in the word
                while (i < n && a[i] != ' ') {
                    ++i;
                }
                continue;
            }
            ++i;
        }
        return sb.toString();
    }

    private void insert(String prefix) {
        TrieNode node = root;
        for (char chr : prefix.toCharArray()) {
            int chrIdx = chr - 'a';
            if (node.get(chrIdx) == null) {
                node.put(chrIdx, new TrieNode());
            }
            node = node.get(chrIdx);
            if (node.isEnd())  return;
        }
        node.setEnd();
    }
}
// @lc code=end

