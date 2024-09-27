/* Write your T-SQL query statement below */
WITH a AS (
    SELECT minute, order_count, CEILING(minute / 6.0) AS interval_no
    FROM Orders
)
SELECT interval_no, SUM(order_count) AS total_orders
FROM a
GROUP BY interval_no
ORDER BY interval_no;
