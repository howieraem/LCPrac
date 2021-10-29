class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        
        while (n) {
            /*
            // Iterate bit by bit
            cnt += (n & 1);
            n >>= 1;
            */

            // Zero the right-most bit 1 and count
            n &= (n - 1);
            ++cnt;
        }

        return cnt;
    }
};
