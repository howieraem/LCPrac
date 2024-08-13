--
-- @lc app=leetcode id=570 lang=mysql
--
-- [570] Managers with at Least 5 Direct Reports
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT e1.name
FROM Employee e1
JOIN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
) e2
ON e1.id = e2.managerId;

-- @lc code=end

