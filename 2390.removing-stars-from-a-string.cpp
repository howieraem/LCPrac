#include <bits/stdc++.h>

using std::string;

class Solution {
public:
    // Two pointers simulating a stack
    // T: O(n)
    // S: O(1) if s can be modified
    string removeStars(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                --j;
            } else {
                s[j++] = s[i];
            }
        }
        return s.substr(0, j);
    }
};