/*
 * @lc app=leetcode.cn id=30 lang=java
 *
 * [30] 串联所有单词的子串
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        // unordered words -> use hashmap to count occurances.
        List<Integer> res = new ArrayList<>();
        int wordNum = words.length;
        if (wordNum == 0)  return res;
        int wordLen = words[0].length();
        HashMap<String, Integer> allWords = new HashMap<>();
        for (String w : words) {
            int val = allWords.getOrDefault(w, 0);
            allWords.put(w, val+1);
        }
        for (int i = 0; i < s.length() - wordNum*wordLen + 1; ++i) {
            HashMap<String, Integer> hasWords = new HashMap<>();
            int num = 0;
            while (num < wordNum) {
                String word = s.substring(i + num*wordLen, i + (num+1)*wordLen);
                if (allWords.containsKey(word)) {
                    int value = hasWords.getOrDefault(word, 0);
                    hasWords.put(word, value + 1);
                    // 判断当前单词的 value 和 allWords 中该单词的 value
                    if (hasWords.get(word) > allWords.get(word)) {
                        break;
                    }
                } else {
                    break;
                }
                ++num;
            }
            if (num == wordNum)  res.add(i);
        }
        return res;
    }
}
// @lc code=end

