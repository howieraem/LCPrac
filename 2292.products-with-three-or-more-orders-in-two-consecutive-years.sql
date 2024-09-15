WITH cte AS (
    SELECT product_id, YEAR(purchase_date) AS yr
    FROM Orders
    GROUP BY product_id, yr
    HAVING COUNT(order_id) >= 3
)
SELECT DISTINCT c1.product_id
FROM cte c1
INNER JOIN cte c2
ON c1.product_id = c2.product_id AND c1.yr = c2.yr + 1;