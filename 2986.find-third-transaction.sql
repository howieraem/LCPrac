WITH cte AS (
    SELECT 
        user_id, 
        spend, 
        transaction_date,
        RANK() OVER (PARTITION BY user_id ORDER BY transaction_date) AS rk,
        LAG(spend) OVER (PARTITION BY user_id ORDER BY transaction_date) AS spend_2nd,
        LAG(spend, 2) OVER (PARTITION BY user_id ORDER BY transaction_date) AS spend_1st
    FROM Transactions
)
SELECT
    user_id,
    spend AS third_transaction_spend,
    transaction_date AS third_transaction_date
FROM cte
WHERE rk = 3 AND spend > spend_2nd AND spend > spend_1st
ORDER BY user_id;
