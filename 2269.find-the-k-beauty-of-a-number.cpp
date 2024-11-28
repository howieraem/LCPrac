class Solution {
public:
    // Math + sliding window 
    // without using string conversion
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        int windowed_num = 0;
        int pow = 1;

        // Process digits from right to left
        for (int x = num; x > 0; x /= 10) {
            windowed_num += (x % 10) * pow;  // shift left pointer of window
            if (k > 1) { // IMPORTANT: stop increasing pow when k = 1, not 0 (because pow(x, 0) = 1, least significant digit)
                pow *= 10;
                --k;
            } else {
                ans += (windowed_num > 0) && (num % windowed_num == 0);
                windowed_num /= 10;  // shift right pointer of window
            }
        }
        return ans;
    }
};