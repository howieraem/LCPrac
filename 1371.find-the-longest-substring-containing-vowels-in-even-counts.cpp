/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */
#include <bits/stdc++.h>

using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
    int get_vowel_idx(char vowel) {
        switch (vowel) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
        }
    }

public:
    // T: O(n)
    // S: O(n)
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mask_to_idx;
        mask_to_idx[0] = -1;    // IMPORTANT

        int mask = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int vi = get_vowel_idx(s[i]);
            if (vi >= 0) {  // flip the bit at the index of the vowel
                mask ^= (1 << vi);
            }

            // As we need the longest substring, use std::unordered_map::insert() 
            // which only updates value if key not exists and then returns a pair 
            // where pair.first points to the pair {key, value} in the map.
            auto p = mask_to_idx.insert({mask, i});

            // Because we are flipping the bits, if the mask already exists, it will
            // give us a substring from that mask to current same mask with even 
            // numbers of vowels.
            // if (i != p.first->second) {
                ans = std::max(ans, i - p.first->second);
            // }
        }
        return ans;
    }
};
// @lc code=end

