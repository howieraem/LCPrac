class Solution {
    // Sorting + Greedy
    // T: O(n * log(n))
    // S: O(n) sorting
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length; i += 2) {
            ans += nums[i];
        }
        return ans;
    }
}