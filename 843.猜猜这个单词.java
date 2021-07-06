import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=843 lang=java
 *
 * [843] 猜猜这个单词
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    private int[][] pairMatches;
    private boolean[] valid;
    private int n;

    public void findSecretWord(String[] wordlist, Master master) {
        n = wordlist.length;

        pairMatches = new int[n][n];
        for (int i = 0; i < n; ++i) {
            pairMatches[i][i] = 6;
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 6; ++k) {
                    if (wordlist[i].charAt(k) == wordlist[j].charAt(k)) {
                        ++cnt;
                    }
                }
                pairMatches[i][j] = pairMatches[j][i] = cnt;
            }
        }

        valid = new boolean[n];
        Arrays.fill(valid, true);

        while (true) {
            int selected = findNext();
            int matches = master.guess(wordlist[selected]);
            if (matches == 6)  return;

            // If the current selected word is not the answer,
            // given the pairMatches of this word, some of the
            // other words can be excluded in future search.
            // 若返回值不为6，那么下一次可挑选的单词和此次挑选单词的相似度肯定是此次的返回值
            for (int i = 0; i < n; ++i) {
                if (pairMatches[selected][i] != matches)
                    valid[i] = false;
            }
        }
    }

    private int findNext() {
        // Min-max strategy:
        // For each word, find the maximum pairMatches w.r.t. other words.
        // Then, find the minimum of all the pairMatches maxima and select 
        // the corresponding word. This reduces the search space.
        // 选择的单词是让最多的与该单词有相同匹配数的单词数最小
        int next = -1, min = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            if (!valid[i])  continue;
            int[] matchesCnt = new int[6];
            for (int j = 0; j < n; ++j) {
                if (j == i || !valid[j])  continue;
                ++matchesCnt[pairMatches[i][j]];
            }

            int curMax = 0;
            for (int cnt : matchesCnt) {
                curMax = Math.max(curMax, cnt);
            }
            if (curMax < min) {
                min = curMax;
                next = i;
            }
        }
        return next;
    }
}
// @lc code=end

