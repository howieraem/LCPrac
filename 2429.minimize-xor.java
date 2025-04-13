class Solution {
    // Bit manipulation
    // T: O(log(x) ^ 2), log(x) := 32 for int type
    // S: O(log(x))
    public int minimizeXor(int num1, int num2) {
        int ones1 = Integer.bitCount(num1);
        int ones2 = Integer.bitCount(num2);

        // If ones1 = ones2, we let ans = num1 to make ans ^ num1 = 0 (minimized)
        // If ones1 > ones2, we let ans = ones2 more significant bits of num1, to minimize ans ^ num1
        // If ones1 < ones2, we let ans = num1 first, and then pick ones2 - ones1 more bits that are not in num1 (iterate from least significant bits)

        int ans = num1;
        for (int i = 0; i < 32; ++i) {
            int mask = (1 << i);
            if (ones1 > ones2 && (mask & num1) > 0) {
                ans ^= mask;
                --ones1;
            }
            if (ones1 < ones2 && (mask & num1) == 0) {
                ans ^= mask;
                ++ones1;
            }
        }
        return ans;
    }
}