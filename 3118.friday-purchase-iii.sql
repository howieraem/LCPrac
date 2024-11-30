/* Write your T-SQL query statement below */
WITH cte1 AS (
    SELECT 
        1 AS week_of_month,
        'VIP' AS membership
    UNION ALL
    SELECT 
        1 AS week_of_month,
        'Premium' AS membership
    UNION ALL
    SELECT 
        2 AS week_of_month,
        'VIP' AS membership
    UNION ALL
    SELECT 
        2 AS week_of_month,
        'Premium' AS membership
    UNION ALL
    SELECT 
        3 AS week_of_month,
        'VIP' AS membership
    UNION ALL
    SELECT 
        3 AS week_of_month,
        'Premium' AS membership  
    UNION ALL
    SELECT 
        4 AS week_of_month,
        'VIP' AS membership
    UNION ALL
    SELECT 
        4 AS week_of_month,
        'Premium' AS membership  
),
cte2 AS (
    SELECT
        ((DATEPART(day, p.purchase_date) - 1) / 7) + 1 AS week_of_month,
        membership,
        SUM(amount_spend) AS total_amount
    FROM Users u
    LEFT JOIN Purchases p 
        ON u.user_id = p.user_id
            AND YEAR(p.purchase_date) = 2023
            AND MONTH(p.purchase_date) = 11
            AND DATENAME(DW, p.purchase_date) = 'Friday'
    WHERE membership != 'Standard'
    GROUP BY ((DATEPART(day, p.purchase_date) - 1) / 7) + 1, membership
)
SELECT c1.week_of_month, c1.membership, COALESCE(c2.total_amount, 0) AS total_amount
FROM cte1 c1
LEFT JOIN cte2 c2
ON c1.week_of_month = c2.week_of_month AND c1.membership = c2.membership
ORDER BY c1.week_of_month, c1.membership;