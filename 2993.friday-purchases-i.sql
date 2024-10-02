/* Write your T-SQL query statement below */
SELECT
    (DATEPART(WEEK, purchase_date) % 11) + 1 AS week_of_month,
    purchase_date,
    SUM(amount_spend) AS total_amount
FROM Purchases
WHERE DATEPART(WEEKDAY, purchase_date) % 6 = 0  -- Friday
GROUP BY purchase_date
HAVING SUM(amount_spend) > 0;