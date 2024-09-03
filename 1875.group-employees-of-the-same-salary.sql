--
-- @lc app=leetcode id=1875 lang=mysql
--
-- [1875] Group Employees of the Same Salary
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        employee_id,
        `name`,
        salary,
        COUNT(employee_id) OVER (PARTITION BY salary) AS cnt
    FROM Employees
)
SELECT employee_id, `name`, salary, DENSE_RANK() OVER (OVER BY salary) as team_id
FROM a
WHERE cnt > 1
ORDER BY team_id, employee_id;

-- @lc code=end

