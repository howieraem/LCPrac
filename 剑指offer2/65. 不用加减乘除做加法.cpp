class Solution {
public:
    int add(int a, int b) {
        int carry = 0;
        /*
        // Method 1: Calculate bit by bit aligned
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int bita = ((a >> i) & 1);
            int bitb = ((b >> i) & 1);
            ans |= ((bita ^ bitb ^ carry) << i);
            carry = (bita & bitb) | (bita & carry) | (bitb & carry);
        }
        return ans;
        */

        // Method 2
        while (b) {
            carry = (a & b);
            a ^= b;
            b = (unsigned) carry << 1;
        }
        return a;
    }
};
