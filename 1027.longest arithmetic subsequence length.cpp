/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        /* 定义状态dp[i][j]为以A[i]和A[j]为最后两个元素的等差数列的长度。
        那么最后两个数定了，前一个元素也就定了为target = 2 * dp[i] - dp[j]， 
        只需要找到i前面最靠近i的target的位置即可。这一解法不限项差的值。
        
        若项差的最大绝对值给定，也可以定义dp[i][diff]为A的前i个元素以diff
        为项差的最长等差子序列长度，其中考虑项差为负则dp的diff维度容量需为
        2*MAX_DIFF+1，这样可以不用哈希表而节省rehash的时间。

        以上两种思路时间复杂度均为O(N^2)。
        */
        unordered_map<int, int> mp;
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int target = 2*A[i] - A[j];
                if (mp.count(target)) {
                    // if target exists in `mp`
                    dp[i][j] = dp[mp[target]][i] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
            mp[A[i]] = i;
        }
        return ans;
    }
};


// @lc code=end
int main() {
    Solution *s = new Solution();
    vector<int> input = {1, 2, 9, 6, 5, 6, 4};
    cout << s->longestArithSeqLength(input) << endl;
    return 0;
}
