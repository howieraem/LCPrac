class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = INT_MAX, ans = 0;
        // 前 i 日最大利润 = max( 前 (i−1) 日最大利润, 第 i 日价格 − 前 i 日最低价格 )
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - curMin);
            curMin = min(curMin, prices[i]);
        }
        return ans;
    }
};
