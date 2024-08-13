--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--

-- @lc code=start
-- Write your MySQL query statement below
/* Window function solution:
SELECT MAX(salary) AS SecondHighestSalary FROM (
    SELECT DISTINCT(salary),
    DENSE_RANK() OVER (ORDER BY salary DESC) rk
    FROM Employee
) a
WHERE rk = 2;
*/

/* Without window function */
SELECT
    (SELECT DISTINCT Salary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary;
-- The subquery alone won't return null if the 2nd highest doesn't exist 

-- @lc code=end

