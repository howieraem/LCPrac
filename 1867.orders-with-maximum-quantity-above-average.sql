--
-- @lc app=leetcode id=1867 lang=mysql
--
-- [1867] Orders With Maximum Quantity Above Average
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT order_id
FROM OrdersDetails
GROUP BY order_id
HAVING MAX(quantity) > ALL(
    SELECT AVG(quantity)
    FROM OrdersDetails
    GROUP BY order_id
);

-- @lc code=end

