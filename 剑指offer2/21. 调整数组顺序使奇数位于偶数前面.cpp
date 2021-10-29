class Solution {
public:
    // left and right pointers
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            /*
            // below is slower
            if (nums[l] & 1) {
                ++l;
                continue;
            }
            if (!(nums[r] & 1)) {
                --r;
                continue;
            }
            swap(nums[l++], nums[r--]);
            */

            while (l < r && (nums[l] & 1))  ++l;
            while (l < r && !(nums[r] & 1))  --r;
            swap(nums[l], nums[r]);
        }
        return nums;
    }

    /*
    // fast and slow pointers
    vector<int> exchange(vector<int>& nums) {
        int slow = 0, fast = 0;
        // fast: the original indices of the odd numbers
        // low: the new indices of the odd numbers 
        while (fast < nums.size()) {
            if (nums[fast] & 1) {
                swap(nums[fast], nums[slow++]);
            }
            ++fast;
        }
        return nums;
    }
    */
};
