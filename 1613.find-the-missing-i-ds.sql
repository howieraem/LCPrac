--
-- @lc app=leetcode id=1613 lang=mysql
--
-- [1613] Find the Missing IDs
--

-- @lc code=start
-- Write your MySQL query statement below
WITH RECURSIVE a AS (
    SELECT 1 AS n
    UNION ALL
    SELECT n + 1
    FROM a
    WHERE n < (SELECT MAX(customer_id) FROM Customers)
)
SELECT n AS ids
FROM a
WHERE n NOT IN (SELECT customer_id FROM Customers);

-- @lc code=end

