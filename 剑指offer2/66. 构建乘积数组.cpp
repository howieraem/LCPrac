class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int prefix = 1, suffix = 1;
        const int n = a.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n; ++i) {
            res[i] *= prefix;
            res[n - i - 1] *= suffix;

            // Do multiplications on prefix and suffix product after 
            // values are assgined to the result container, so that
            // the result would not involve the ith number
            prefix *= a[i];
            suffix *= a[n - i - 1];
        }
        return res;
    }
};
