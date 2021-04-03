/*
 * @lc app=leetcode.cn id=1006 lang=java
 *
 * [1006] 笨阶乘
 */
// import java.util.Stack;

// @lc code=start
class Solution {
    // public int clumsy(int N) {
    //     Stack<Integer> s = new Stack<>();
    //     s.add(N);
    //     --N;
    //     int i = 0;
    //     while (N > 0) {
    //         switch (i % 4) {
    //             case 0:
    //                 s.push(s.pop() * N);
    //                 break;
    //             case 1:
    //                 s.push(s.pop() / N);
    //                 break;
    //             case 2:
    //                 s.push(N);
    //                 break;
    //             case 3:
    //                 s.push(-N);
    //                 break;
    //         }
    //         --N;
    //         ++i;
    //     }

    //     int ans = 0;
    //     for (int num : s) {
    //         ans += num;
    //     }
    //     return ans;
    // }

    public int clumsy(int N) {
        if (N < 3)  return N;
        if (N == 3)  return 6;
        if (N == 4)  return 7;

        int remainder = N % 4;
        if (remainder == 0)  return N + 1;
        else if (remainder <= 2)  return N + 2;
        else  return N - 1;
    }
}
// @lc code=end

