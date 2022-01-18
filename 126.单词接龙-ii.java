/*
 * @lc app=leetcode.cn id=126 lang=java
 *
 * [126] 单词接龙 II
 */
import java.util.*;

// @lc code=start
class Solution {
    @SuppressWarnings("unchecked")
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Map<String, Integer> wordId = new HashMap<>(); // 单词到id的映射
        ArrayList<String> idWord = new ArrayList<>(); // id到单词的映射

        /** 构建图 */
        int id = 0;
        // 将wordList所有单词加入wordId中，相同的只保留一个，并为每一个单词分配一个id
        for (String word : wordList) {
            if (!wordId.containsKey(word)) { 
                wordId.put(word, id++);
                idWord.add(word);
            }
        }
        // 若endWord不在wordList中，则无解
        if (!wordId.containsKey(endWord)) {
            return new ArrayList<>();
        }
        // 把beginWord也加入wordId中
        if (!wordId.containsKey(beginWord)) {
            wordId.put(beginWord, id++);
            idWord.add(beginWord);
        }

        // 初始化存边用的数组
        ArrayList<Integer>[] edges = new ArrayList[idWord.size()];
        for (int i = 0; i < idWord.size(); ++i) {
            edges[i] = new ArrayList<>();
        }
        // 添加边
        for (int i = 0; i < idWord.size(); ++i) {
            for (int j = i + 1; j < idWord.size(); ++j) {
                // 若两者可以通过转换得到 则在它们间建一条无向边
                String str1 = idWord.get(i), str2 = idWord.get(j);
                int differences = 0;
                for (int k = 0; k < str1.length() && differences < 2; ++k) {
                    if (str1.charAt(k) != str2.charAt(k))  ++differences;
                }
                if (differences == 1) {
                    edges[i].add(j);
                    edges[j].add(i);
                }
            }
        }

        /** BFS */
        int dest = wordId.get(endWord); // 目的地ID
        List<List<String>> res = new ArrayList<>(); // 存答案
        int[] cost = new int[id]; // 到每个点的代价
        for (int i = 0; i < id; ++i) {
            cost[i] = Integer.MAX_VALUE; // 每个点的代价初始化为无穷大
        }

        // 将起点加入队列 并将其cost设为0
        Queue<ArrayList<Integer>> q = new LinkedList<>();
        ArrayList<Integer> initPath = new ArrayList<>();
        initPath.add(wordId.get(beginWord));
        q.add(initPath);
        cost[wordId.get(beginWord)] = 0;

        // 搜索
        while (!q.isEmpty()) {
            ArrayList<Integer> curPath = q.poll();
            int last = curPath.get(curPath.size() - 1); // 最近访问的点
            if (last == dest) { // 若该点为终点则将其存入答案res中
                ArrayList<String> resPath = new ArrayList<>();
                for (int index : curPath) {
                    resPath.add(idWord.get(index)); // 转换为对应的word
                }
                res.add(resPath);
            } else { // 该点不为终点 继续搜索
                for (int i = 0; i < edges[last].size(); ++i) {
                    int next = edges[last].get(i);
                    // 检查next是否已被访问
                    // cost[next]等于Integer.MAX_VALUE时表示next尚未被访问。
                    // 此处`<=`目的在于把代价相同的不同路径全部保留下来。
                    if (cost[last] + 1 <= cost[next]) {
                        cost[next] = cost[last] + 1;
                        // 把next加入路径中
                        ArrayList<Integer> path = new ArrayList<>(curPath); 
                        path.add(next);
                        q.add(path); // 把这个路径加入队列
                    }
                }
            }
        }
        return res;
    }
}
// @lc code=end

