/*
 * @lc app=leetcode id=155 lang=java
 *
 * [155] Min Stack
 */
import java.util.Stack;

// @lc code=start
/* 
// Solution with built-in stack. S: O(n)
class MinStack {
    private Stack<Integer> nums, mins;

    public MinStack() {
        nums = new Stack<>();
        mins = new Stack<>();  // maintains the minimum value at the time of each push()
    }
    
    // T: O(1)
    public void push(int val) {
        nums.push(val);
        if (mins.empty() || mins.peek() > val) {
            mins.push(val);
        } else {
            mins.push(mins.peek());
        }
    }
    
    // T: O(1)
    public void pop() {
        if (!nums.empty()) {
            nums.pop();
            mins.pop();
        }
    }
    
    // T: O(1)
    public int top() {
        return nums.peek();
    }
    
    // T: O(1)
    public int getMin() {
        return mins.peek();
    }
}
*/

// Linked list solution. S: O(n)
class MinStack {
    private class Node {
        int val, min;
        Node next;

        Node(int _val, int _min, Node _next) {
            val = _val;
            min = _min;
            next = _next;
        }
    }

    private Node head;

    public MinStack() {}
    
    // T: O(1)
    public void push(int val) {
        if (head == null) {
            head = new Node(val, val, null);
        } else {
            head = new Node(val, Math.min(val, head.min), head);
        }
    }
    
    // T: O(1)
    public void pop() {
        head = head.next;
    }
    
    // T: O(1)
    public int top() {
        return head.val;
    }
    
    // T: O(1)
    public int getMin() {
        return head.min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @lc code=end

