import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=212 lang=java
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
    // using code from q208
    private TrieNode root;
    
    private class TrieNode {
        TrieNode[] children;
        boolean isEnd;

        public TrieNode() {
            children = new TrieNode[26];
            isEnd = false;
        }
    }
    
    /** Inserts a word into the trie. */
    private void insert(String word) {
        TrieNode tmp = root;
        // for (char chr: word.toCharArray()) {
        for (int i = 0; i < word.length(); ++i) {
            char chr = word.charAt(i);
            int chrIdx = chr - 'a';
            if (tmp.children[chrIdx] == null) {
                tmp.children[chrIdx] = new TrieNode();
            }
            tmp = tmp.children[chrIdx];
        }
        tmp.isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    private boolean search(String word) {
        TrieNode tmp = root;
        for (int i = 0; i < word.length(); ++i) {
            char cur = word.charAt(i);
            int chrIdx = cur - 'a';
            if (tmp.children[chrIdx] == null)  return false;
            tmp = tmp.children[chrIdx];
        }
        return tmp.isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    private boolean startsWith(String prefix) {
        TrieNode tmp = root;
        for (int i = 0; i < prefix.length(); ++i) {
            char cur = prefix.charAt(i);
            int chrIdx = cur - 'a';
            if (tmp.children[chrIdx] == null)  return false;
            tmp = tmp.children[chrIdx];
        }
        return true;
    }

    private int m, n;
    private char[][] b;
    private static final int[][] D = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public List<String> findWords(char[][] board, String[] words) {
        b = board;
        m = board.length; 
        if (m == 0)  return new ArrayList<>();
        n = board[0].length;
        if (n == 0)  return new ArrayList<>();
        
        root = new TrieNode();
        for (String w : words) {
            insert(w);
        }
        Set<String> res = new HashSet<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                StringBuilder sb = new StringBuilder();
                boolean[][] marked = new boolean[m][n];
                helper(i, j, marked, sb, res);
            }
        }
        return new ArrayList<>(res);
    }

    private void helper(int x, int y, boolean[][] marked, StringBuilder path, Set<String> res) {
        path.append(b[x][y]);
        String str = path.toString();
        if (marked[x][y] || !startsWith(str)) {
            path.deleteCharAt(path.length() - 1);
            return;
        }

        marked[x][y] = true;
        if (search(str) && !res.contains(str)) {
            res.add(str);
        }

        for (int[] dirn : D) {
            int nx = x + dirn[0], ny = y + dirn[1];
            if (inBound(nx, ny))  helper(nx, ny, marked, path, res);
        }
        path.deleteCharAt(path.length() - 1);
        marked[x][y] = false;
    }

    private boolean inBound(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}
// @lc code=end

