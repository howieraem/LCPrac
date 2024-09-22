/* Write your T-SQL query statement below */
WITH a AS (
    SELECT user_id, product_id, SUM(quantity) AS tot_quant
    FROM Sales
    GROUP BY user_id, product_id
),
b AS (
    SELECT 
        a.user_id,
        a.product_id,
        DENSE_RANK() OVER (PARTITION BY a.user_id ORDER BY a.tot_quant * p.price DESC) AS rk
    FROM a
    LEFT JOIN Product p ON a.product_id = p.product_id 
)
SELECT user_id, product_id
FROM b
WHERE rk = 1;