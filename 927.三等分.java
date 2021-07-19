// import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=927 lang=java
 *
 * [927] 三等分
 */

// @lc code=start
class Solution {
    // public int[] threeEqualParts(int[] arr) {
    //     int count1 = Arrays.stream(arr).sum();
    //     // If the count of ones is not divisible by 3,
    //     // then it is impossible to partition.
    //     if (count1 % 3 != 0)  return new int[]{-1, -1};
    //     int n = arr.length;
    //     if (count1 == 0)  return new int[]{0, n - 1};
    //     int countSeg = count1 / 3;
        
    //     int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
    //     int s = 0;
    //     for (int i = 0; i < n; ++i) {
    //         if (arr[i] == 0)  continue;
    //         ++s;
    //         if (s == 1)  i1 = i;
    //         if (s == countSeg) j1 = i;
    //         if (s == countSeg + 1) i2 = i;
    //         if (s == countSeg * 2) j2 = i;
    //         if (s == countSeg * 2 + 1) i3 = i;
    //         if (s == countSeg * 3) j3 = i;
    //     }

    //     // compare parts that start and end with a one
    //     int[] arr1 = Arrays.copyOfRange(arr, i1, j1 + 1);
    //     int[] arr2 = Arrays.copyOfRange(arr, i2, j2 + 1);
    //     int[] arr3 = Arrays.copyOfRange(arr, i3, j3 + 1);
    //     if (!Arrays.equals(arr1, arr2) || !Arrays.equals(arr2, arr3)) 
    //         return new int[]{-1, -1};

    //     // compare no. of zeros after each part
    //     int z1 = i2 - j1 - 1, z2 = i3 - j2 - 1, z3 = n - j3 - 1;
    //     if (z1 < z3 || z2 < z3)  return new int[]{-1, -1};
    //     return new int[]{j1 + z3, j2 + z3 + 1};
    // }

    public int[] threeEqualParts(int[] arr) {
        int n = arr.length;
        int[] prefixSum = new int[n];
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        int sum = prefixSum[n - 1];
        // If the count of ones is not divisible by 3,
        // then it is impossible to partition.
        if (sum % 3 != 0)  return new int[]{-1, -1};
        if (sum == 0)  return new int[]{0, n - 1};

        int lastZeros = 0;
        while (arr[n - 1 - lastZeros] == 0) {
            ++lastZeros;
        }

        // Do binary search on prefixSum which is ordered
        // to find the partition indices more efficiently.
        // The lower bounds already takes leading zeros
        // into account, so just shift them according to 
        // trailing zeros found for the 3rd part to get 
        // parition indices. 
        int i = lowerBound(prefixSum, n, sum / 3) + lastZeros;
        int j = lowerBound(prefixSum, n, sum * 2 / 3);
        if (i >= j)  return new int[]{-1, -1};
        j += lastZeros + 1;

        // Verify each subarray
        int end1 = i, end2 = j - 1, end3 = n - 1;
        while (end1 >= 0 && end2 > i && end3 >= j) {
            if (arr[end1] == arr[end2] && arr[end2] == arr[end3]) {
                --end1;
                --end2;
                --end3;
            } else {
                return new int[]{-1, -1};
            }
        }
        return new int[]{i, j};
    }

    private int lowerBound(int[] arr, int n, int target) {
        int l = 0, r = n;
        while (l < r) {
            int m = ((r - l) >> 1) + l;
            if (arr[m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }
}
// @lc code=end

