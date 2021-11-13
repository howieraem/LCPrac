class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for (auto &c : s) {
            ++cnt[c - 'a'];
        }

        for (auto &c : s) {
            if (cnt[c - 'a'] == 1)  return c;
        }
        return ' ';
    }
};
