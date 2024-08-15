--
-- @lc app=leetcode id=1070 lang=mysql
--
-- [1070] Product Sales Analysis III
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        product_id, 
        `year`, 
        quantity,
        price,
        RANK() OVER (PARTITION BY product_id ORDER BY `year`) AS rk
    FROM Sales
)
SELECT product_id, `year` AS first_year, quantity, price
FROM a
WHERE rk = 1;

-- @lc code=end

