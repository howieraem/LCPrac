/* solution 1: without window func */
SELECT 
    DISTINCT a.visited_on, 
    SUM(b.amount) AS amount,
    ROUND(SUM(b.amount) / 7.00, 2) AS average_amount 
FROM Customer a
INNER JOIN Customer b
ON DATEDIFF(a.visited_on, b.visited_on) BETWEEN 0 AND 6
GROUP BY a.visited_on, a.customer_id
HAVING COUNT(DISTINCT b.visited_on) = 7
ORDER BY a.visited_on;

/* solution 2: with window func 
SELECT DISTINCT visited_on,
    SUM(amount) OVER w AS amount,
    ROUND((SUM(amount) OVER w) / 7.00, 2) AS average_amount
FROM Customer
WINDOW w AS (
    ORDER BY visited_on
    RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW
)
LIMIT 9999 OFFSET 6  -- MySQL requires a limit given an offset
*/