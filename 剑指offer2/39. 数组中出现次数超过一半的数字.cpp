class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, ans = nums[0];
        for (auto &num : nums) {
            if (num == ans)  ++cnt;
            else if (!(--cnt)) {
                cnt = 1;
                ans = num;
            }
        }
        return ans;
    }
};