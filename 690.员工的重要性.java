/*
 * @lc app=leetcode.cn id=690 lang=java
 *
 * [690] 员工的重要性
 */
import java.util.Map;
import java.util.HashMap;


class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
}
// @lc code=start
/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> d = new HashMap<>();
        for (Employee e : employees) {
            d.put(e.id, e);
        }
        return helper(d, id);
    }

    private int helper(Map<Integer, Employee> d, int id) {
        Employee e = d.get(id);
        for (int subId : e.subordinates) {
            e.importance += helper(d, subId);
        }
        return e.importance;
    }
}
// @lc code=end

