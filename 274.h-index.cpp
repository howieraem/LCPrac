/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution with std::sort()
    // T: O(n * log(n))
    // S: O(log(n)) (introsort)
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        const int n = citations.size();
        if (citations[0] >= n)  return n;
        for (int i = 1; i < n; ++i) {
            int h = n - i;
            if (citations[i] >= h && citations[i - 1] <= h)  return h;
        }
        return 0;
    }
    */

    // Solution based on counting sort.
    // T: O(n)
    // S: O(n)
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        vector<int> freq(n + 1, 0);     // maximum possible h-index is the number of citations 
        for (const int& c : citations) {
            if (c >= n) {
                ++freq[n];
            } else {
                ++freq[c];
            }
        }

        int cnt = 0;
        for (int i = n; i >= 0; --i) {
            cnt += freq[i];
            if (cnt >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

