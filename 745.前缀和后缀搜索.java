import java.util.*;
/*
 * @lc app=leetcode.cn id=745 lang=java
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
/** Solution with 2 tries, 1 for prefix and 1 for suffix */

class TrieNode {
    TrieNode[] next;
    List<Integer> idxs;

    public TrieNode() {
        next = new TrieNode[26];
        idxs = new ArrayList<>();
    }
}

class WordFilter {
    TrieNode rootP, rootS;
    Map<String, Integer> cache;

    public WordFilter(String[] words) {
        rootP = new TrieNode();
        rootS = new TrieNode();
        cache = new HashMap<>();

        for (int i = 0; i < words.length; ++i) {
            char[] w = words[i].toCharArray();

            // Insert all prefixes
            TrieNode cur = rootP;
            for (char c : w) {
                int ci = c - 'a';
                if (cur.next[ci] == null) {
                    cur.next[ci] = new TrieNode();
                }
                cur.idxs.add(i);
                cur = cur.next[ci];
            }
            cur.idxs.add(i);

            // Insert all suffixes
            cur = rootS;
            for (int j = w.length - 1; j >= 0; --j) {
                int ci = w[j] - 'a';
                if (cur.next[ci] == null) {
                    cur.next[ci] = new TrieNode();
                }
                cur.idxs.add(i);
                cur = cur.next[ci];
            }
            cur.idxs.add(i);
        }
    }
    
    public int f(String prefix, String suffix) {
        String key = prefix + '_' + suffix;
        if (cache.containsKey(key))  return cache.get(key);

        // Find prefix indices
        TrieNode np = rootP;
        for (char c : prefix.toCharArray()) {
            np = np.next[c - 'a'];
            if (np == null) {
                cache.put(key, -1);
                return -1;
            }
        }

        // Find suffix indices
        char[] sa = suffix.toCharArray();
        TrieNode ns = rootS;
        for (int idx = sa.length - 1; idx >= 0; --idx) {
            ns = ns.next[sa[idx] - 'a'];
            if (ns == null) {
                cache.put(key, -1);
                return -1;
            }
        }

        // If there is more than one valid index, return the largest of them
        int i = np.idxs.size() - 1, j = ns.idxs.size() - 1;
        while (i >= 0 && j >= 0) {
            int ip = np.idxs.get(i), is = ns.idxs.get(j);
            if (ip == is) {
                cache.put(key, ip);
                return ip;
            } else if (ip > is) {
                --i;
            } else {
                --j;
            }
        }
        cache.put(key, -1);
        return -1;
    }
}

// class WordFilter {
//     Map<String, Integer> d;

//     public WordFilter(String[] words) {
//         d = new HashMap<>();
//         for (int i = 0; i < words.length; ++i) {
//             char[] w = words[i].toCharArray();
//             int n = w.length;
//             StringBuilder prefix = new StringBuilder();
//             for (int j = 0; j <= n; ++j) {
//                 if (j > 0)  prefix.append(w[j - 1]);
//                 String suffix = "";
//                 for (int k = n; k >= 0; --k) {
//                     if (k != n)  suffix = w[k] + suffix;
//                     d.put(prefix.toString() + '_' + suffix, i);
//                 }
//             }
//         }
//     }
    
//     public int f(String prefix, String suffix) {
//         return d.getOrDefault(prefix + '_' + suffix, -1);
//     }
// }

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
// @lc code=end

