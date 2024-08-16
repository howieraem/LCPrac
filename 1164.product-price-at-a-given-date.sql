--
-- @lc app=leetcode id=1164 lang=mysql
--
-- [1164] Product Price at a Given Date
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT product_id, 10 AS price
FROM Products
GROUP BY product_id
HAVING MIN(change_date) > '2019-08-16'

UNION

SELECT p1.product_id, p1.new_price AS price
FROM Products p1
INNER JOIN (
    SELECT product_id, MAX(change_date) AS recent
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
) p2
ON p1.product_id = p2.product_id AND p1.change_date = p2.recent;

-- @lc code=end

