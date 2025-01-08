/* Write your T-SQL query statement below */
SELECT
    transaction_date,
    SUM(CASE WHEN amount & 1 = 1 THEN amount ELSE 0 END) AS odd_sum,
    SUM(CASE WHEN amount & 1 = 0 THEN amount ELSE 0 END) AS even_sum
FROM transactions
GROUP BY transaction_date
ORDER BY transaction_date;