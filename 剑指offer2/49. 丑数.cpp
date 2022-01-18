class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            int u2 = (nums[i2] << 1);
            int u3 = nums[i3] * 3;
            int u5 = nums[i5] * 5;
            int ugly = min(u2, min(u3, u5));
            i2 += (ugly == u2);
            i3 += (ugly == u3);
            i5 += (ugly == u5);
            nums[i] = ugly;
        }
        return nums.back();
    }
};
