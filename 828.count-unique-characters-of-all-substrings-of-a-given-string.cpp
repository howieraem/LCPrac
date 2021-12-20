/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */
#include <string>

using std::string;

// @lc code=start
/*
Example:
    Think about string "XAXAXXAX" and focus on making the second "A" a unique character.
    We can take "XA(XAXX)AX" and between "()" is our substring.
    We can see here, to make the second "A" counted as a uniq character, we need to:
        1. insert "(" somewhere between the first and second A
        2. insert ")" somewhere between the second and third A
    For step 1 we have "A(XA" and "AX(A", 2 possibility.
    For step 2 we have "A)XXA", "AX)XA" and "AXX)A", 3 possibilities.

    So there are in total 2 * 3 = 6 ways to make the second A a unique character in a substring.
    In other words, there are only 6 substring, in which this A contribute 1 point as unique string.
*/
class Solution {
public:
    // Instead of counting all unique characters and struggling with all possible substrings,
    // we can count for every char in S, how many ways to be found as a unique char.
    // We count and sum, and it will be the answer.
    // T: O(n)
    // S: O(s), s := alphabet size
    int uniqueLetterString(string s) {
        const int n = s.size();
        int idxs[26][2], ans = 0;
        memset(idxs, -1, sizeof(idxs));
        for (int i = 0; i < n; ++i) {
            int cidx = s[i] - 'A';
            ans += (i - idxs[cidx][1]) * (idxs[cidx][1] - idxs[cidx][0]);
            idxs[cidx][0] = idxs[cidx][1];
            idxs[cidx][1] = i;
        }
        for (int c = 0; c < 26; ++c) {
            ans += (n - idxs[c][1]) * (idxs[c][1] - idxs[c][0]);
        }
        return ans;
    }

    /*
    // A more general solution which does not depend on alphabet set.
    // T: O(n ^ 2)
    // S: O(1)
    int uniqueLetterString(string s) {
        int ans = 0;
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && s[l] != s[i]) --l;
            while (r < n && s[r] != s[i])  ++r;
            ans += (r - i) * (i - l);
        }
        return ans;
    }
    */
};
// @lc code=end

