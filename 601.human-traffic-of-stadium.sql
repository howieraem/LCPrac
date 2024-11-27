/* Write your PL/SQL query statement below */
WITH a AS (
    SELECT 
        s.id,
        s.visit_date,
        s.people,
        id - ROW_NUMBER() OVER (ORDER BY id) AS diff
    FROM Stadium s
    WHERE s.people >= 100
), b AS (
    SELECT diff
    FROM a
    GROUP BY diff
    HAVING COUNT(*) >= 3
)
SELECT a.id, to_char(a.visit_date, 'yyyy-mm-dd') AS visit_date, a.people
FROM a
JOIN b ON a.diff = b.diff;