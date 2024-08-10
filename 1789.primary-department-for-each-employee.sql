--
-- @lc app=leetcode id=1789 lang=mysql
--
-- [1789] Primary Department for Each Employee
--

-- @lc code=start
-- Write your MySQL query statement below
with a AS (
    SELECT 
        *,
        COUNT(1) OVER (PARTITION BY employee_id) cnt
    FROM Employee
)
SELECT
    employee_id,
    department_id
FROM a
WHERE primary_flag = 'Y' 
    OR cnt = 1;

-- @lc code=end

