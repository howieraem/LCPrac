SELECT o.customer_id, c.customer_name
FROM Orders o
INNER JOIN Customers c
ON o.customer_id = c.customer_id
GROUP BY o.customer_id, c.customer_name
HAVING SUM(CASE WHEN o.product_name = 'A' THEN 1 ELSE 0 END) > 0
    AND SUM(CASE WHEN o.product_name = 'B' THEN 1 ELSE 0 END) > 0
    AND SUM(CASE WHEN o.product_name = 'C' THEN 1 ELSE 0 END) = 0
ORDER BY o.customer_id;
