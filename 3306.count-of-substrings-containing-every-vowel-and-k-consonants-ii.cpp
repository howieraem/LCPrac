#include <bits/stdc++.h>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
    static inline const unordered_map<char, int> VOWEL_IDXS {
            {'a', 0},
            {'e', 1},
            {'i', 2},
            {'o', 3},
            {'u', 4}
    };

    // Find the number of substrs with at least k consonants and exactly 5 types of vowels
    long long countAtLeastKConsonants(const string& word, const int& k) {
        vector<int> vowel_cnts(5);
        int n_unique_vowel = 0;
        int n_con = 0;
        long long ans = 0;
        int l = 0;
        for (int r = 0; r < word.size(); ++r) {
            auto r_it = VOWEL_IDXS.find(word[r]);
            if (r_it == VOWEL_IDXS.end()) {
                ++n_con;
            } else {
                n_unique_vowel += (++vowel_cnts[r_it->second] == 1);
            }

            while (n_unique_vowel == 5 && n_con >= k) {
                ans += (long long) word.size() - r;
                auto l_it = VOWEL_IDXS.find(word[l++]);
                if (l_it == VOWEL_IDXS.end()) {
                    --n_con;
                } else {
                    n_unique_vowel -= (--vowel_cnts[l_it->second] == 0);
                }
            }
        }
        return ans;
    }

public:
    // Similar to Q992
    // T: O(len(word))
    // S: O(len(word))
    long long countOfSubstrings(string word, int k) {
        return countAtLeastKConsonants(word, k) - countAtLeastKConsonants(word, k + 1);
    }
};