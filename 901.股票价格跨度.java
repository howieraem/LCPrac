import java.util.*;
/*
 * @lc app=leetcode.cn id=901 lang=java
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
    private Stack<Integer> prices;
    private Stack<Integer> lens;

    public StockSpanner() {
        prices = new Stack<>();
        lens = new Stack<>();
    }

    public int next(int price) {
        int len = 1;
        while (!prices.empty() && prices.peek() <= price) {
            prices.pop();
            len += lens.pop();
        }
        prices.push(price);
        lens.push(len);
        return len;
    }
}

// class StockSpanner {
//     private Stack<Integer> stack;
//     private List<Integer> data;

//     public StockSpanner() {
//         stack = new Stack<>();
//         data = new ArrayList<>();
//     }

//     public int next(int price) {
//         int ans;
//         data.add(price);
//         // Mono-stack storing indices
//         while (!stack.empty() && data.get(stack.peek()) <= price) {
//             stack.pop();
//         }
//         // If stack is empty, `price` is greater than
//         // or equal to all existing prices.
//         // Stack top is the index of the next greater element of `price` in data,
//         // so the maximum consecutive days will be `data.size() - 1 - stack.peek()`.
//         ans = stack.empty() ? data.size() : data.size() - 1 - stack.peek();
//         stack.push(data.size() - 1);
//         return ans;
//     }
// }

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
// @lc code=end

