#include <bits/stdc++.h>

// T: O(n * k)
// S: O(k)
long long max_observable_sum(const std::vector<int>& prices, int k) {
    std::unordered_set<int> window_nums;
    int l = 0, r = 0;
    long long ans = 0;
    while (r < prices.size()) {
        while (window_nums.find(prices[r]) != window_nums.end()) {
            window_nums.erase(prices[l++]);
        }
        window_nums.insert(prices[r++]);
        if (r - l == k) {
            long long window_sum = 0;
            for (int i = l; i < r; ++i) {
                window_sum += prices[i];
            }
            ans = std::max(ans, window_sum);
            ++l;
        }
    }
    return ans != 0 ? ans : -1;
}
