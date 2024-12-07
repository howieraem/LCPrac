#include <string>

using std::string;

class Solution {
    inline char next_char(const char& c) {
        return c == 'z' ? 'a' : c + 1;
    }

public:
    // Two pointers
    // T: O(n)
    // S: O(1)
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        while (i < str1.size() && j < str2.size()) {
            j += (str1[i] == str2[j] || next_char(str1[i]) == str2[j]);
            ++i;
        }
        return j == str2.size();
    }
};