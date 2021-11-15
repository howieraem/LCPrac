class Solution {
public:
    // Solution based on sliding window.
    // NOTE: string can contain any ASCII symbols! 
    // If unsure about what symbols involved,
    // use a hashmap instead.
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0;
        vector<int> freq(256, 0);
        while (r < s.size()) {
            int c = s[r];
            ++freq[c];
            while (freq[c] > 1) {
                --freq[s[l]];
                ++l;
            }
            ++r;
            ans = max(r - l, ans);
        }
        return ans;
    }
};
