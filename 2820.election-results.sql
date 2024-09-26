/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        voter,
        candidate,
        1.0 / COUNT(candidate) OVER (PARTITION BY voter) AS voter2cand
    FROM Votes
    WHERE candidate IS NOT NULL
),
b AS (
    SELECT 
        candidate,
        RANK() OVER (ORDER BY SUM(voter2cand) DESC) AS rk
    FROM a
    GROUP BY candidate -- IMPORTANT: ORDER BY SUM in window function above
)
SELECT candidate
FROM b
WHERE rk = 1
ORDER BY candidate;