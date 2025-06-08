class Solution {
    // Two pointers
    // T: O(min(m, n))
    // S: O(1)
    public int appendCharacters(String s, String t) {
        final int m = s.length();
        final int n = t.length();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (s.charAt(i) == t.charAt(j)) {
                ++j;
            }
            ++i;
        }
        return n - j;
    }
}