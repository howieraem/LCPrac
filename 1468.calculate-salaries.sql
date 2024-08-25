--
-- @lc app=leetcode id=1468 lang=mysql
--
-- [1468] Calculate Salaries
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    company_id,
    employee_id,
    employee_name,
    ROUND(
        CASE
            WHEN MAX(salary) OVER (PARTITION BY company_id) > 10000 THEN salary * 0.51
            WHEN MAX(salary) OVER (PARTITION BY company_id) BETWEEN 1000 AND 10000 THEN salary * 0.76
            ELSE salary
        END,
        0
    ) AS salary
FROM Salaries

-- @lc code=end

