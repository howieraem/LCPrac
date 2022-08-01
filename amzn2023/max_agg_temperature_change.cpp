/**
 * https://curly-oriole-764.notion.site/22ec8523c820410490092ace51489509?v=a65d5dfe1dae443385cd3bbd0aa3ce9a&p=1135ba34e0f34a05a1549019809455c2&pm=s
 *
 * Example:
 * changes = [1, 2, -3]
 * day0: max(1, 1 + 2 - 3) = 1
 * day1: max(1 + 2, 2 - 3) = 3
 * day2: max(1 + 2 - 3, -3) = 0
 * ans = max(day0, day1, day2) = 3 
 */
#include <bits/stdc++.h>

// T: O(n)
// S: O(n)
long long max_agg_temperature_change(const std::vector<int>& changes) {
    const int n = changes.size();
    std::vector<long long> pre_sum(n);
    pre_sum[0] = changes[0];
    for (int i = 1; i < n; ++i) {
        pre_sum[i] = pre_sum[i - 1] + changes[i];
    }

    long long ans = std::max(pre_sum.front(), pre_sum.back());
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, std::max(pre_sum[i], pre_sum.back() - pre_sum[i - 1]));
    }
    return ans;
}
