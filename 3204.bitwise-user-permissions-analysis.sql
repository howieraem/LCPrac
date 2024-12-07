/* Write your T-SQL query statement below */
-- In MySQL or Postgres, we can use BIT_AND() and BIT_OR() aggregation functions directly
WITH a AS (
    SELECT
        permissions,
        ROW_NUMBER() OVER (ORDER BY (SELECT NULL)) AS rn
    FROM user_permissions
),
recursive_cte AS (
    SELECT
        permissions AS value_and,
        permissions AS value_or,
        rn
    FROM a
    WHERE rn = 1
    UNION ALL
    SELECT
        r.value_and & a.permissions AS value_and,
        r.value_or | a.permissions AS value_or,
        r.rn + 1
    FROM recursive_cte r
    JOIN a ON r.rn + 1 = a.rn
)
SELECT
    MIN(value_and) AS common_perms,
    MAX(value_or) AS any_perms
FROM recursive_cte;