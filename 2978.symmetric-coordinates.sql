/* Write your T-SQL query statement below */
WITH a AS (
    SELECT c1.X, c1.Y
    FROM Coordinates c1
    JOIN Coordinates c2
    ON c1.X = c2.Y AND c1.Y = c2.X
    WHERE c1.X < c1.Y  -- avoid selecting just one entry of c1.X = c1.Y
    UNION 
    SELECT X, Y
    FROM Coordinates
    WHERE X = Y
    GROUP BY X, Y
    HAVING COUNT(*) > 1
)
SELECT X, Y
FROM a
ORDER BY X;