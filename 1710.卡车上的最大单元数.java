/*
 * @lc app=leetcode.cn id=1710 lang=java
 *
 * [1710] 卡车上的最大单元数
 */
// import java.util.Arrays;

// @lc code=start
class Solution {
    // public int maximumUnits(int[][] boxTypes, int truckSize) {
    //     // Use boxes with greater capacity first
    //     Arrays.sort(boxTypes, (b1, b2) -> b2[1] - b1[1]);

    //     int ans = 0;
    //     for (int[] boxType : boxTypes) {
    //         int boxNum = boxType[0], boxCap = boxType[1];
    //         if (boxNum <= truckSize) {
    //             ans += boxNum * boxCap;
    //             truckSize -= boxNum;
    //         } else {
    //             ans += truckSize * boxCap;
    //             break;
    //         }
    //     }
    //     return ans;
    // }

    public int maximumUnits(int[][] boxTypes, int truckSize) {
        // Since the max box capacity is known and not too considerable,
        // it is faster to count boxes per capacity and sum them up while
        // less than truck size.
        int[] capCnts = new int[1000];
        for (int[] boxType : boxTypes) {
            capCnts[boxType[1] - 1] += boxType[0];
        }

        int ans = 0;
        for (int i = 1000; i > 0; --i) {
            int capCnt = capCnts[i - 1];
            if (capCnt != 0) {
                if (capCnt < truckSize) {
                    ans += capCnt * i;
                    truckSize -= capCnt;
                } else {
                    return ans + truckSize * i;
                }
            }
        }
        return ans;
    }
}
// @lc code=end

