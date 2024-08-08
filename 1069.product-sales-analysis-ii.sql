--
-- @lc app=leetcode id=1069 lang=mysql
--
-- [1069] Product Sales Analysis II
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT product_id, SUM(quantity) AS total_quantity
FROM Sales
GROUP BY product_id;

-- @lc code=end

