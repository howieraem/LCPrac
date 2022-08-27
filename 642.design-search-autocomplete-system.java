/*
 * @lc app=leetcode id=642 lang=java
 *
 * [642] Design Search Autocomplete System
 */
import java.util.*;

// @lc code=start
class AutocompleteSystem {
    class TrieNode {
        TrieNode[] children;
        Map<String, Integer> cnts;
        boolean isWord;

        TrieNode() {
            children = new TrieNode[28];
            cnts = new HashMap<>();
            isWord = false;
        }
    }

    private static final int K = 3;
    private TrieNode root;
    private StringBuilder prefix;

    // T: O(n * l), n := len(sentences), l := sentence length
    public AutocompleteSystem(String[] sentences, int[] times) {
        root = new TrieNode();
        prefix = new StringBuilder();
        for (int i = 0; i < sentences.length; ++i) {
            addWord(sentences[i], times[i]);
        }
    }
    
    // T: O(l + n * log(K)), l := prefix length, n := the number of common prefixes
    public List<String> input(char c) {
        if (c == '#') {
            addWord(prefix.toString(), 1);
            prefix.setLength(0);  // clear the prefix
            return new ArrayList<>();
        }

        prefix.append(c);
        TrieNode cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            char ch = prefix.charAt(i);
            int cIdx = getCharIdx(ch);
            if (cur.children[cIdx] == null) {
                return new ArrayList<>();
            }
            cur = cur.children[cIdx];
        }

        Map<String, Integer> prefixCnts = cur.cnts;
        // Compare counts and then ASCII code
        PriorityQueue<String> minHeap = new PriorityQueue<>(
                (a, b) -> (prefixCnts.get(a) == prefixCnts.get(b) ? b.compareTo(a) : Integer.compare(prefixCnts.get(a), prefixCnts.get(b))));
        
        for (String key : prefixCnts.keySet()) {
            minHeap.offer(key);
            if (minHeap.size() > K) {
                minHeap.poll();
            }
        }
        
        final int heapSize = minHeap.size();  // can be less than K
        String[] res = new String[heapSize];
        // Because the heap size is limited to K by polling, 
        // need to insert to result container reversely
        for (int i = heapSize - 1; i >= 0; --i) {
            res[i] = minHeap.poll();
        }

        return Arrays.asList(res);
    }

    private void addWord(String s, int cnt) {
        TrieNode cur = root;
        for (char c : s.toCharArray()) {
            int cIdx = getCharIdx(c);
            if (cur.children[cIdx] == null) {
                cur.children[cIdx] = new TrieNode();
            }
            cur = cur.children[cIdx];
            cur.cnts.put(s, cur.cnts.getOrDefault(s, 0) + cnt);
        }
        cur.isWord = true;
    }

    private static int getCharIdx(char c) {
        switch (c) {
            case ' ':
                return 26;
            case '#':
                return 27;
            default:
                return c - 'a';
        }
    }
}

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */
// @lc code=end

