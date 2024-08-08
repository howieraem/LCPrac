--
-- @lc app=leetcode id=1076 lang=mysql
--
-- [1076] Project Employees II
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        project_id,
        DENSE_RANK() OVER (ORDER BY COUNT(employee_id) DESC) as rk
    FROM Project
    GROUP BY project_id
)
SELECT project_id
FROM a
WHERE rk = 1;

-- @lc code=end

