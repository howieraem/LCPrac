#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    // T: O(log(k))
    // S: O(1)
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        k -= 1;
        int limit = std::min((int)operations.size(), 64);
        for (int i = 0; i < limit; ++i) {
            // operations[i] is applied when the i-th bit in k-1 is 1 
            ans += ((k >> i) & 1) && operations[i];
        }
        return ans % 26 + 'a';
    }
};