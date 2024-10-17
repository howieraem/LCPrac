/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
typedef pair<string, int> wc;

class Solution {
public:
    // T: O(n * log(k))
    // S: O(n)
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;
        for (const string& w : words) {
            ++f[w];
        }

        // Sort by count DESC and then by lexicographical order ASC
        // Comparator symbols are reversed, because we fix the heap size at k and keep popping less frequent words
        auto cmp = [&](const wc& p1, const wc& p2) {
            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
        };
        priority_queue<wc, vector<wc>, decltype(cmp)> min_heap(cmp);
        for (const auto& e : f) {
            min_heap.push(e);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // Results are written to the container reversely as heap
        // top is always the node with smallest freq. 
        vector<string> res(k, "");
        int p = k - 1;
        while (!min_heap.empty()) {
            res[p--] = min_heap.top().first; min_heap.pop();
        }
        return res;
    }
};
// @lc code=end

