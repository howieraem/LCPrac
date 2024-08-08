--
-- @lc app=leetcode id=1083 lang=mysql
--
-- [1083] Sales Analysis II
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT s.buyer_id
FROM Sales s
LEFT JOIN Product p
ON s.product_id = p.product_id
GROUP BY s.buyer_id
HAVING SUM(CASE WHEN p.product_name = 'S8' THEN 1 ELSE 0 END) > 0
    AND SUM(CASE WHEN p.product_name = 'iPhone' THEN 1 ELSE 0 END) = 0; 

-- @lc code=end

