/*
 * @lc app=leetcode.cn id=332 lang=java
 *
 * [332] 重新安排行程
 */
import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Stack;

// @lc code=start
class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> res = new LinkedList<>();
        if (tickets == null || tickets.size() == 0)  return res;
        
        Map<String, PriorityQueue<String>> graph = new HashMap<>();
        for (List<String> edge : tickets) {
            // using priority queue to store neighbors in their natural order
            PriorityQueue<String> nodeNeighbors = graph.computeIfAbsent(edge.get(0), k -> new PriorityQueue<>());
            nodeNeighbors.add(edge.get(1));
        }

        visit(graph, "JFK", res);
        return res;
    }

    private void visit(Map<String, PriorityQueue<String>> graph, String cur, List<String> res) {
        Stack<String> stk = new Stack<>();
        stk.push(cur);

        while (!stk.isEmpty()) {
            PriorityQueue<String> nodeNeighbors;
            while ((nodeNeighbors = graph.get(stk.peek())) != null && !nodeNeighbors.isEmpty()) {
                stk.push(nodeNeighbors.poll());     // push smaller ones to stack first
            }
            // Stack top is the largest in stack, so pop and insert to the list head. 
            // Use LinkedList for O(1) head insertion.
            res.add(0, stk.pop());
        }
    }
}
// @lc code=end

