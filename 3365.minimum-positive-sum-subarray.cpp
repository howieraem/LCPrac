#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Hash maps
    // T: O(n)
    // S: O(n)
    bool isPossibleToRearrange(string s, string t, int k) {
        if (s.size() != t.size()) {
            return false;
        }
        const int len = s.size() / k;
        
        string_view sv(s);
        string_view tv(t);
        unordered_map<string_view, int> substr_freqs1;
        unordered_map<string_view, int> substr_freqs2;
        for (int i = 0; i < s.size(); i += len) {
            ++substr_freqs1[sv.substr(i, len)];
            ++substr_freqs2[tv.substr(i, len)];
        }
        return substr_freqs1 == substr_freqs2;
    }
};