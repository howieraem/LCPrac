--
-- @lc app=leetcode id=1174 lang=mysql
--
-- [1174] Immediate Food Delivery II
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    ROUND(SUM(
        CASE 
            WHEN order_date = customer_pref_delivery_date THEN 1.00
            ELSE 0.00
        END) * 100 / COUNT(*), 2) AS immediate_percentage
FROM Delivery d1
WHERE EXISTS (
    SELECT 1
    FROM (
        SELECT customer_id, MIN(order_date) AS first_date
        FROM Delivery
        GROUP BY customer_id
    ) d2
    WHERE d1.order_date = d2.first_date AND d1.customer_id = d2.customer_id
);

-- @lc code=end

