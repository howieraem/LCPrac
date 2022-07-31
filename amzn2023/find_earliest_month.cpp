/**
 * https://www.1point3acres.com/bbs/thread-843804-1-1.html
 * 
 * Given a list of stock prices, find a pivot index splitting the list into two sublists,
 * such that the difference between the average of the first half and the average of the 
 * second half is the least.
 */
#include <bits/stdc++.h>

using std::vector;

// T: O(n)
// S: O(n)
int find_earliest_month(const vector<int>& prices) {
    const int n = prices.size();
    vector<long long> pre_sum(n);
    pre_sum[0] = prices[0];
    for (int i = 1; i < n; ++i) {
        pre_sum[i] = pre_sum[i - 1] + prices[i];
    }
    long long min_d = INT_MAX;
    int ans = 0;
    for (long long i = 0; i < n - 1; ++i) {
        long long avg_l = pre_sum[i] / (i + 1);
        long long avg_r = (pre_sum[n - 1] - pre_sum[i]) / (n - 1 - i);
        long long d = std::abs(avg_l - avg_r);
        if (d < min_d) {
            min_d = d;
            ans = i;
        }
    }
    return ans + 1;  // 1-indexed
}
