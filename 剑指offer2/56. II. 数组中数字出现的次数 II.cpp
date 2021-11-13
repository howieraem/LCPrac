class Solution {
public:
    // Solution based on state machine.
    // See https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/ 
    // for more explanations.
    int singleNumber(vector<int>& nums) {
        int bit1 = 0, bit2 = 0;
        for (auto &n : nums) {
            bit1 = bit1 ^ n & ~bit2;
            bit2 = bit2 ^ n & ~bit1;
        }
        return bit1;
    }

    /*
    // Solution with an auxiliary array.
    int singleNumber(vector<int>& nums) {
        vector<int> bit_cnt(32);
        for (auto &n : nums) {
            for (int i = 0; i < 32; ++i) {
                bit_cnt[i] += ((n >> i) & 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans |= ((bit_cnt[i] % 3) << i);
        }
        return ans;
    }
    */
};