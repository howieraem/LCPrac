class Solution {
public:
    /*
    // Solution 1: Find all arithmetic progressions with difference 1 that sum up to target
    // target = a0 * n + n * (n - 1) / 2
    // n ^ 2 / 2 + (a0 - 1 / 2) * n - target = 0 
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> ret;
        int half = target >> 1;
        for (int i = 1; i <= half; ++i) {
            int n = solveQuadratic(i, target);
            if (n > 0) {
                ret.clear();
                for (int j = 0; j < n; ++j) {
                    ret.push_back(i + j);
                }
                res.push_back(ret);
            }
        }
        return res;
    }

    int solveQuadratic(int a0, int target) {
        // Get a positive root of n for the following equation:
        // n ^ 2 + (2 * a0 - 1) * n - 2 * target = 0
        double b = 2. * a0 - 1, c = -2. * target;
        double n = (-b + sqrt(b * b - 4 * c)) / 2.;
        double intpart;
        return modf(n, &intpart) == 0.0 ? (int) n : -1;  // check if n is an integer
    }
    */


    // Solution 2: similar idea to above, but avoids solving equation and dealing with floating point.
    // target = (a0 + an) / 2
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> ret;
        int l = 1, r = 2;
        while (l < r) {
            int sum = ((l + r) * (r - l + 1)) >> 1;
            if (sum > target) {
                ++l;
            } else if (sum < target) {
                ++r;
            } else {
                ret.clear();
                for (int i = l; i <= r; ++i) {
                    ret.push_back(i);
                }
                res.push_back(ret);
                ++l;
            }
        }
        return res;
    }
};
