/*
 * @lc app=leetcode id=1258 lang=java
 *
 * [1258] Synonymous Sentences
 */
import java.util.*;

// @lc code=start
class Solution {
    // Graph + BFS
    // T: O((V + E) * log(V + E))
    // S: O(V + E)
    public List<String> generateSentences(List<List<String>> synonyms, String text) {
        Map<String, List<String>> graph = new HashMap<>();
        for (List<String> edge : synonyms) {
            String v = edge.get(0);
            String w = edge.get(1);

            // Undirected
            graph.putIfAbsent(v, new ArrayList<>());
            graph.get(v).add(w);
            graph.putIfAbsent(w, new ArrayList<>());
            graph.get(w).add(v);
        }

        Queue<String> q = new ArrayDeque<>();
        q.add(text);
        Set<String> vis = new TreeSet<>();  // sorted lexicographically
        vis.add(text);

        while (!q.isEmpty()) {
            String s = q.poll();
            String[] words = s.split("\\s+");
            for (int i = 0; i < words.length; ++i) {
                List<String> wordSyms = graph.get(words[i]);
                if (wordSyms == null) {
                    continue;
                }

                for (String sy : wordSyms) {
                    words[i] = sy;
                    String newSentence = String.join(" ", words);
                    if (!vis.contains(newSentence)) {
                        q.add(newSentence);
                        vis.add(newSentence);
                    }
                }
            }
        }

        return new ArrayList<>(vis);
    }
}
// @lc code=end

