import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1472 lang=java
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
class BrowserHistory {
    private static final int MAX_SZ = 5000;
    // might be even faster with fixed-size array if max size is known
    private List<String> history;   
    private int p, sz;

    public BrowserHistory(String homepage) {
        history = new ArrayList<>(MAX_SZ);
        p = -1;
        sz = 0;
        visit(homepage);
    }
    
    public void visit(String url) {
        ++p;
        if (history.size() <= p) {
            history.add(url);
        } else {
            history.set(p, url);
        }
        sz = p + 1;
    }
    
    public String back(int steps) {
        p = p > steps ? p - steps : 0;
        return history.get(p);
    }
    
    public String forward(int steps) {
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

