class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] == m)  l = m + 1;   // the missing number is on the right half subarray
            else  r = m - 1;
        }
        return l;
    }
};
