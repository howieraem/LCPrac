/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT 
        user_id, 
        purchase_date,
        LAG(purchase_date) OVER (PARTITION BY user_id ORDER BY purchase_date) pre_purchase_date
    FROM Purchases
)
SELECT DISTINCT user_id
FROM cte
WHERE DATEDIFF(DAY, pre_purchase_date, purchase_date) <= 7;