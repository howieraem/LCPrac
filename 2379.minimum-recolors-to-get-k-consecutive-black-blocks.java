class Solution {
    // Sliding window
    // T: O(n)
    // S: O(1)
    public int minimumRecolors(String blocks, int k) {
        int window_b_cnt = 0;
        int ans = blocks.length();
        for (int r = 0; r < blocks.length(); ++r) {
            if (blocks.charAt(r) == 'B') {
                ++window_b_cnt;
            }
            if (r - k >= 0 && blocks.charAt(r - k) == 'B') {
                --window_b_cnt;
            }
            ans = Math.min(ans, k - window_b_cnt);
        }
        return ans;
    }
}
