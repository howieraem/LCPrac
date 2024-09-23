/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        id, 
        drink, 
        ROW_NUMBER() OVER (ORDER BY (SELECT NULL)) AS rn
    FROM CoffeeShop
),
b AS (
    SELECT 
        id, 
        drink, 
        rn,
        COUNT(drink) OVER (ORDER BY rn) AS group_id  -- null contributes 0 to COUNT
    FROM a
)
SELECT 
    id, 
    FIRST_VALUE(drink) OVER (PARTITION BY group_id ORDER BY rn) AS drink
FROM b;