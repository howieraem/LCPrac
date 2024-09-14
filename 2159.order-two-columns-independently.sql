WITH a AS (
    SELECT first_col, ROW_NUMBER() OVER (ORDER BY first_col) as rn
    FROM Data
), b AS (
    SELECT second_col, ROW_NUMBER() OVER (ORDER BY second_col DESC) as rn
    FROM Data
)
SELECT a.first_col, b.second_col
FROM a
INNER JOIN b
ON a.rn = b.rn;
