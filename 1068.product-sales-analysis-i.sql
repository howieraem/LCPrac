--
-- @lc app=leetcode id=1068 lang=mysql
--
-- [1068] Product Sales Analysis I
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT product_name, `year`, price
FROM Sales s
LEFT JOIN Product p
ON s.product_id = p.product_id;

-- @lc code=end

