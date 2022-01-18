import java.util.*;

/*
 * @lc app=leetcode.cn id=1178 lang=java
 *
 * [1178] 猜字谜
 */

// @lc code=start
class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        // Pre-compute the 26-bit mask for each word meaning the types of characters present.
        // Since some words may have the same mask, count the mask occurences for convenience.
        Map<Integer, Integer> wordMaskCnt = new HashMap<>();
        for (String word : words) {
            int mask = 0;
            char[] a = word.toCharArray();
            for (char c : a) {
                mask |= (1 << (c - 'a'));
            }
            wordMaskCnt.put(mask, wordMaskCnt.getOrDefault(mask, 0) + 1);
        }

        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < puzzles.length; ++i) {
            char[] puzzle = puzzles[i].toCharArray();
            int pMask = 0;
            for (int idx = 0; idx < puzzle.length; ++idx) {
                pMask |= (1 << (puzzle[idx] - 'a'));
            }

            int cnt = 0;
            // Get the binary subset of pMask,
            // i.e. each element in the subset
            // is pMask with any bit 1's changed
            // to 0's.
            int binSubset = pMask;
            int firstCharMask = (1 << (puzzle[0] - 'a'));   // ensure first char the same
            do {
                // Enumerate the subset by negating each 1's in pMask
                binSubset = ((binSubset - 1) & pMask);
                if ((firstCharMask & binSubset) != 0) {
                    cnt += wordMaskCnt.getOrDefault(binSubset, 0);
                }
            // in the final iteration, bitSubset = 0, (0 - 1) & pMask = (0b111...111) & pMask = pMask
            } while (binSubset != pMask);
            res.add(cnt);
        }
        return res;
    }
}
// @lc code=end

