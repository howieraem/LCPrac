#include <bits/stdc++.h>

using std::pair;
using std::set;
using std::unordered_map;
using std::vector;

class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();
        vector<long long> res(n - k + 1);
        int p = 0;

        unordered_map<int, long long> cnts;
        set<pair<long long, int>, std::greater<pair<long long, int>>> top;  // top x frequent (cnt, num)
        set<pair<long long, int>, std::greater<pair<long long, int>>> bottom; // other (cnt, num)

        long long window_sum = 0LL;

        for (int r = 0; r < n; ++r) {
            long long cnt = cnts[nums[r]];

            // update cnt
            if (cnt > 0) {
                auto tup = std::make_pair(cnt, nums[r]); 
                auto it = bottom.find(tup);
                if (it != bottom.end()) {
                    bottom.erase(it);
                } else {
                    // must be in top
                    top.erase(tup);
                    window_sum -= cnt * nums[r];
                }
            }
            ++cnt;
            cnts[nums[r]] = cnt;
            top.insert({cnt, nums[r]});
            window_sum += cnt * nums[r];

            // rebalance
            if (top.size() > x) {
                auto top_least_it = std::prev(top.end());
                window_sum -= top_least_it->first * top_least_it->second;
                bottom.insert({top_least_it->first, top_least_it->second});
                top.erase(top_least_it);
            }

            // sliding window
            if (r >= k) {
                int l = r - k;
                long long l_cnt = cnts[nums[l]];
                auto l_tup = std::make_pair(l_cnt, nums[l]);
                auto l_it = bottom.find(l_tup);
                if (l_it != bottom.end()) {
                    bottom.erase(l_it);
                } else {
                    // must be in the top set
                    window_sum -= l_cnt * nums[l];
                    top.erase(l_tup);
                }

                --l_cnt;
                cnts[nums[l]] = l_cnt;
                if (l_cnt > 0) {
                    bottom.insert({l_cnt, nums[l]});
                }

                // rebalance
                if (top.size() < x) {
                    auto bottom_greatest_it = bottom.begin();
                    if (bottom_greatest_it != bottom.end()) {
                        window_sum += bottom_greatest_it->first * bottom_greatest_it->second;
                        top.insert({bottom_greatest_it->first, bottom_greatest_it->second});
                        bottom.erase(bottom_greatest_it);
                    }
                }
            }

            if (r + 1 >= k) {
                res[p++] = window_sum;
            }
        }

        return res;
    }
};