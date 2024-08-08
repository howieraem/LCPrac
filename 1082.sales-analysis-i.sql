--
-- @lc app=leetcode id=1082 lang=mysql
--
-- [1082] Sales Analysis I
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        seller_id,
        DENSE_RANK() OVER (ORDER BY SUM(price) DESC) as rk
    FROM Sales 
    GROUP BY seller_id
)
SELECT seller_id
FROM a
WHERE rk = 1; 
-- @lc code=end

