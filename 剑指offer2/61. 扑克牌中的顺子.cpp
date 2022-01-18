class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_set<int> s;
        int minN = 14, maxN = -1; 
        for (int i = 0; i < nums.size(); ++i) {
            // 跳过大小王
            if (nums[i]) {
                // 检查是否有重复的牌
                if (s.find(nums[i]) != s.end())  return false;
                s.insert(nums[i]);
                minN = min(minN, nums[i]);
                maxN = max(maxN, nums[i]);
            }   
        }
        return maxN - minN < 5;
    }
};
