/**
 * Given strings search_word and result_word, how many characters need to be 
 * appended to search_word such that result_word becomes a subsequence of 
 * search_word? 
 */
#include <string>

using std::string;

// Dual pointer
// T: O(min(len(search_word), len(result_word)))
// S: O(1)
int make_subseq(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            ++i, ++j;
        } else {
            ++i;
        }
    }
    return t.size() - j;
}
