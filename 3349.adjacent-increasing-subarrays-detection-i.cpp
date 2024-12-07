#include <vector>

using std::vector;

class Solution {
public:
    // 1D DP
    // T: O(n)
    // S: O(1)
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int pre_len = 0;
        int cur_len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cur_len;
            } else {
                // the two subarrs must be adjacent
                pre_len = cur_len;
                cur_len = 1;
            }

            // case 1: max(subarr1) >= min(subarr2)
            // case 2: max(subarr1) < min(subarr2), subarr1 and subarr2 form a subarr with length 2k
            if ((pre_len >= k && cur_len >= k) || cur_len >= (k << 1)) {
                return true;
            }
        }

        return false;
    }
};