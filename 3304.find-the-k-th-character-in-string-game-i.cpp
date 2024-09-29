#include <bits/stdc++.h>

using std::string;

class Solution {
public:
    // T: O(k)
    // S: O(k)
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string tmp;
            for (auto c : s) {
                if (c == 'z') {
                    tmp.push_back('a');
                } else {
                    tmp.push_back(c + 1);
                }
                if (tmp.size() + s.size() == k) {
                    return tmp.back();
                }
            }
            s.append(std::move(tmp));
        }
        return s[k - 1];
    }

    // Math method
    // T: O(log(k))
    // S: O(1) ?
    // char kthCharacter(int k) {
    //     return (__builtin_popcount(k - 1) % 26) + 'a'; 
    // }
};