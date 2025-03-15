class Solution {
    // Array + 2D Matrix
    // T: O(m * n)
    // S: O(1)
    public int[] rowAndMaximumOnes(int[][] mat) {
        int[] res = {0, 0};
        for (int r = 0; r < mat.length; ++r) {
            int rowOnes = 0;
            for (int c = 0; c < mat[r].length; ++c) {
                if (mat[r][c] == 1) {
                    ++rowOnes;
                }
            }
            if (rowOnes > res[1]) {
                res[1] = rowOnes;
                res[0] = r;
            }
        }
        return res;
    }
}
