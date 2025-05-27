class Solution {
    // Kadane's algo variant + 1D DP + Math + Hash Map
    // T: O(n)
    // S: O(value_space), value_space := 50
    public int maxFrequency(int[] nums, int k) {
        int[] cnts = new int[51];
        int subArrayCntK = 0;
        for (int x : nums) {
            // Pick a subarray, count the biggest frequency of any value.
            // For the rest part of this subarray, count the frequency of k
            // We don't care about the actual difference added to numbers of this subarray.
            cnts[x] = Math.max(cnts[x], cnts[k]) + 1;
            
            subArrayCntK = Math.max(subArrayCntK, cnts[x] - cnts[k]);
        }
        return cnts[k] + subArrayCntK;
    }
}