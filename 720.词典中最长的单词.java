// import java.util.*;
/*
 * @lc app=leetcode.cn id=720 lang=java
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class TrieNode {
    TrieNode[] next;
    int wordIdx;

    public TrieNode() {
        next = new TrieNode[26];
        wordIdx = -1;
    }
}

class Solution {
    // public String longestWord(String[] words) {
    //     Arrays.sort(words);
    //     String ans = "";
    //     Set<String> set = new HashSet<>();
    //     for (String s : words) {
    //         if (s.length() == 1 || set.contains(s.substring(0, s.length() - 1))) {
    //             if (s.length() > ans.length()) {
    //                 ans = s;
    //             }
    //             set.add(s);
    //         }
    //     }
    //     return ans;
    // }

    private TrieNode root;
    private String[] ws;
    private String ans;

    public String longestWord(String[] words) {
        root = new TrieNode();
        ans = "";
        ws = words;
        insertAll();
        for (int i = 0; i < 26; ++i) {
            dfs(root.next[i]);
        }
        return ans;
    }

    private void insertAll() {
        TrieNode node;
        for (int i = 0; i < ws.length; ++i) {
            node = root;
            for (char c : ws[i].toCharArray()) {
                int j = c - 'a';
                if (node.next[j] == null) {
                    node.next[j] = new TrieNode();
                }
                node = node.next[j];
            }
            node.wordIdx = i;
        }
    }

    private void dfs(TrieNode node) {
        if (node != null && node.wordIdx != -1) {
            String w = ws[node.wordIdx];
            if (w.length() > ans.length() || (w.length() == ans.length() && w.compareTo(ans) < 0)) {
                ans = w;
            }

            for (int i = 0; i < 26; ++i) {
                dfs(node.next[i]);
            }
        }
    }
}
// @lc code=end

