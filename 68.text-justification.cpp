/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        
        for (int i = 0, j; i < words.size(); i = j) {
            // Find words and spaces needed for a line
            int width = 0;
            for (j = i; j < words.size() && width + words[j].size() + j - i <= maxWidth; j++) {
                width += words[j].size();
            }
            int space = 1, extra = 0;
            if (j - i != 1 && j != words.size()) {
                space = (maxWidth - width) / (j - i - 1);
                extra = (maxWidth - width) % (j - i - 1);
            }

            // Build a line from words[i:j] with spaces 
            string line(words[i]);
            for (int k = i + 1; k < j; ++k) {
                // Add space between words
                line += string(space, ' ');
                if (extra-- > 0) {
                    line.push_back(' ');
                }

                // Append next word
                line += words[k];
            }

            // Padding right 
            line += string(maxWidth - line.size(), ' ');
            res.push_back(line);
        }

        return res;
    }
};
// @lc code=end

