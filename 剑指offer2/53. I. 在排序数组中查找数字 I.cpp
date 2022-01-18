class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size())  return 0;
        int l = lowerBound(nums, target);
        if (l == -1)  return 0;     // target not found

        // Below is faster if the target does not appear very frequently, O(N)
        int r = l;
        while (r < nums.size() && nums[r] == target)  ++r;
        return r - l;

        // Below is faster if the target value usually appear very frequently, O(log(N))
        // return upperBound(nums, target) - l + 1;
    }

    static int lowerBound(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] < target)  l = m + 1;
            else  r = m - 1;
        }
        return (l >= nums.size() || nums[l] != target) ? -1 : l;
    }

    static int upperBound(vector<int> &nums, int target) {
        int l = 0, r= nums.size() - 1, m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] > target)  r = m - 1;
            else  l = m + 1;
        }
        return (r < 0 || nums[r] != target) ? -1 : r;
    }
};
