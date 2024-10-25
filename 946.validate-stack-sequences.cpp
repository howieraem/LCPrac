/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution with an auxiliary stack in O(N) space.
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        int p = 0;
        for (auto &num : pushed) {
            stack.push_back(num);
            while (!stack.empty() && stack.back() == popped[p]) {
                stack.pop_back();
                ++p;
            }
        }
        return stack.empty();
    }
    */

    /** 
     * Solution in O(1) space assuming the original data is allowed to be 
     * modified in place. 
     */
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        // Reuse `pushed` as a stack, and do simulation
        for (auto& num : pushed) {
            pushed[i++] = num;  // simulate push
            while (i > 0 && pushed[i - 1] == popped[j]) {   // simulate pop: !pushed.empty() && pushed.top() = popped[j]
                --i; 
                ++j;
            }
        }
        return i == 0;
    }
};
// @lc code=end

