/* Write your T-SQL query statement below */
SELECT 'bull' AS word, SUM(CASE WHEN content LIKE '% bull %' THEN 1 ELSE 0 END) AS count
FROM Files
UNION ALL
SELECT 'bear' AS word, SUM(CASE WHEN content LIKE '% bear %' THEN 1 ELSE 0 END) AS count
FROM Files