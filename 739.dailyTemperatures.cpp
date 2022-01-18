/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        // Mono-stack stores indices of day where 
        // day temperatures are ascending from
        // stack top to stack bottom.
        stack<int> st;  
        for (int i = 0; i < T.size(); ++i) {
            while (!st.empty() && T[i] > T[st.top()]) {
                auto t = st.top(); st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

