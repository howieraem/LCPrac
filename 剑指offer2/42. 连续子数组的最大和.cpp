class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            // dp[i] = max(dp[i - 1] + nums[i], nums[i])
            // dp[i] means the maximum sum of the subarray that ends at nums[i]
            cur = max(cur + nums[i], nums[i]);  // state compressed
            ans = max(cur, ans);
        }
        return ans;
    }
};
