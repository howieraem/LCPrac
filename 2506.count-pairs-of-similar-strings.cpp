#include <bits/stdc++.h>

class Solution {
public:
    // T: O(sum(len(w) for w in words))
    // S: O(len(words))
    int similarPairs(std::vector<std::string>& words) {
        int ans = 0;
        std::unordered_map<int, int> mask_freq;
        for (const auto& w : words) {
            int mask = 0;
            for (const auto& c : w) {
                mask |= 1 << (c - 'a');  // char c exists
            }
            ans += mask_freq[mask]++;
        }
        return ans;
    }
};