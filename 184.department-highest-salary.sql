--
-- @lc app=leetcode id=184 lang=mysql
--
-- [184] Department Highest Salary
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT `Department`, `Employee`, `Salary`
FROM (
    SELECT 
        d.name as `Department`,
        e.name as `Employee`,
        e.salary as `Salary`,
        DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS rk
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id
) t 
WHERE rk = 1;
-- @lc code=end

