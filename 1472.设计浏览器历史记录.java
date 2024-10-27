import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1472 lang=java
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
// Array and current pointers to simulate stack
// S: O(n)
class BrowserHistory {
    private static final int MAX_SZ = 5000;
    private List<String> history;
    private int sz;   
    private int p;

    // T: O(1)
    public BrowserHistory(String homepage) {
        history = new ArrayList<>(MAX_SZ);
        p = -1;
        sz = 0;
        visit(homepage);
    }
    
    // T: O(1)
    public void visit(String url) {
        ++p;
        if (history.size() <= p) {
            history.add(url);
        } else {
            // p is not at the back of the list
            history.set(p, url);
        }
        sz = p + 1;
    }
    
    // T: O(1)
    public String back(int steps) {
        // p = max(0, p - steps)
        p = p > steps ? p - steps : 0;
        return history.get(p);
    }
    
    // T: O(1)
    public String forward(int steps) {
        // p = min(p + steps, sz - 1)
        p = p + steps >= sz ? sz - 1 : p + steps;
        return history.get(p);
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
// @lc code=end

