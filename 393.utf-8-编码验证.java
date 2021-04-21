/*
 * @lc app=leetcode.cn id=393 lang=java
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
    public boolean validUtf8(int[] data) {
        int nBytesToProc = 0;

        // for quick checking whether the most two significant bits are 1 and 0 respectively
        int mask1 = 1 << 7, mask2 = 1 << 6;

        for (int i = 0; i < data.length; ++i) {
            // String bin = Integer.toBinaryString(data[i]);
            // if (bin.length() >= 8) {
            //     // take the least significant 8 bits
            //     bin = bin.substring(bin.length() - 8);
            // } else {
            //     // pad zeros to the left
            //     bin = "00000000".substring(bin.length() % 8) + bin;
            // }

            if (nBytesToProc == 0) {
                // count the number of digit 1s in the beginning of the string
                // for (int j = 0; j < bin.length(); ++j) {
                //     if (bin.charAt(j) == '0')  break;
                //     ++nBytesToProc;
                // }
                int mask = 1 << 7;
                while ((mask & data[i]) != 0) {
                    ++nBytesToProc;
                    mask >>= 1;
                }

                if (nBytesToProc == 0)  continue; // 1-byte UTF8 character

                if (nBytesToProc > 4 || nBytesToProc == 1)  return false;
            } else {
                // the following bytes must start with "10" while nBytesToProc > 0
                // if (!(bin.charAt(0) == '1' && bin.charAt(1) == '0'))  return false;
                if (!((data[i] & mask1) != 0 && (data[i] & mask2) == 0))  return false;
            }
            --nBytesToProc;
        }
        return nBytesToProc == 0;
    }
}
// @lc code=end

