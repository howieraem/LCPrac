import java.util.*;

/*
 * @lc app=leetcode.cn id=187 lang=java
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
    private static final int L = 10;

    /*
    // ordinary slicing
    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        if (n <= L)  return new ArrayList<>();
        Set<String> seen = new HashSet<>(), res = new HashSet<>();

        for (int start = 0; start < n - L + 1; ++start) {
            String tmp = s.substring(start, start + L);
            if (seen.contains(tmp))  res.add(tmp);
            seen.add(tmp);
        }
        return new ArrayList<String>(res);
    }
    */

    // Rabin-Karp Algorithm
    private static final Map<Character, Integer> map = 
        new HashMap<>() {
            private static final long serialVersionUID = 1L;

            {
                put('A', 0); 
                put('C', 1);
                put('G', 2);
                put('T', 3);
            }
        };
    private static final int A = 4;
    private static final int AL = (int) Math.pow(A, L);

    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        if (n <= L)  return new ArrayList<>();
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = map.get(s.charAt(i));
        }

        Set<Integer> seen = new HashSet<>(); 
        Set<String> res = new HashSet<>();
        int subSeqHash = 0;
        for (int start = 0; start < n - L + 1; ++start) {
            if (start == 0) {
                // compute hash of the first subsequence in O(L) time
                for (int i = 0; i < L; ++i) {
                    subSeqHash = subSeqHash * A + nums[i];
                }
            } else {
                // compute hash of other subsequences, each in O(1) time
                subSeqHash = subSeqHash * A - nums[start - 1] * AL + nums[start + L - 1];
            }

            if (seen.contains(subSeqHash))  res.add(s.substring(start, start+L));
            seen.add(subSeqHash);
        }
        return new ArrayList<String>(res);
    }
}
// @lc code=end

