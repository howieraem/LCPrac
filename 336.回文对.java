/*
 * @lc app=leetcode.cn id=336 lang=java
 *
 * [336] 回文对
 */
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;


// @lc code=start
class Solution {
    List<String> wordsRev = new ArrayList<>();
    Map<String, Integer> indices = new HashMap<>();

    public List<List<Integer>> palindromePairs(String[] words) {
        int n = words.length;
        for (String word : words) {
            wordsRev.add(new StringBuffer(word).reverse().toString());
        }
        for (int i = 0; i < n; ++i) {
            indices.put(wordsRev.get(i), i);
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String word = words[i];
            int m = words[i].length();
            if (m == 0) {
                continue;
            }
            for (int j = 0; j <= m; ++j) {
                if (isPalindrome(word, j, m - 1)) {
                    // s[j:m-1] is a palindrome, and the reverse of s[0:j-1] exists in `words`
                    // Note: when j == m, isPalindrome(j, m - 1) returns true because empty string is treated as palindrome
                    int leftIdx = findWord(word, 0, j - 1);
                    if (leftIdx != -1 && leftIdx != i) {
                        res.add(Arrays.asList(i, leftIdx));
                    }
                }
                if (j != 0 && isPalindrome(word, 0, j - 1)) {
                    // s[0:j-1] is a palindrome, and the reverse of s[j:m-1] exists in `words`
                    int rightIdx = findWord(word, j, m - 1);
                    if (rightIdx != -1 && rightIdx != i) {
                        res.add(Arrays.asList(rightIdx, i));
                    }
                }
            }
        }
        return res;
    }

    private boolean isPalindrome(String s, int left, int right) {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++) {
            if (s.charAt(left + i) != s.charAt(right - i)) {
                return false;
            }
        }
        return true;
    }

    private int findWord(String s, int left, int right) {
        return indices.getOrDefault(s.substring(left, right + 1), -1);
    }
}
// @lc code=end

