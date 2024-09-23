/* Write your T-SQL query statement below */
SELECT 
    s1.salesperson_id,
    s1.name,
    COALESCE(SUM(s2.price), 0) AS total
FROM Salesperson s1
LEFT JOIN Customer c ON s1.salesperson_id = c.salesperson_id
LEFT JOIN Sales s2 ON c.customer_id = s2.customer_id
GROUP BY s1.salesperson_id, s1.name;
