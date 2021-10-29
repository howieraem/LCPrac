class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (!matrix.size() || !matrix[0].size())  return res;
        const int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = cols - 1, t = 0, b = rows - 1;
        while (l <= r && t <= b) {
            // From left to right, top row
            for (int i = l; i <= r; ++i) {
                res.push_back(matrix[t][i]);
            }

            // From top to bottom, right column
            for (int j = t + 1; j <= b; ++j) {
                res.push_back(matrix[j][r]);
            }

            // Be aware of the inner-most loop
            if (l < r && t < b) {
                // From right to left, bottom row 
                for (int i = r - 1; i > l; --i) {
                    res.push_back(matrix[b][i]);
                }

                // From bottom to top, left row
                for (int j = b; j > t; --j) {
                    res.push_back(matrix[j][l]);
                }
            }
            ++l; --r; ++t; --b;
        }
        return res;
    }
};
