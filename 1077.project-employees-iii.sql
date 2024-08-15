--
-- @lc app=leetcode id=1077 lang=mysql
--
-- [1077] Project Employees III
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        p.project_id,
        e.employee_id,
        RANK() OVER (PARTITION BY p.project_id ORDER BY e.experience_years DESC) AS rk
    FROM Project p
    LEFT JOIN Employee e
    ON p.employee_id = e.employee_id 
)
SELECT project_id, employee_id
FROM a
WHERE rk = 1;


-- @lc code=end

