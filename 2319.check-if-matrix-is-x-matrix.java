class Solution {
    // Matrix + 2D array
    // T: O(n ^ 2)
    // S: O(1)
    public boolean checkXMatrix(int[][] grid) {
        final int n = grid.length;
        if (n == 0) {
            return false;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
}