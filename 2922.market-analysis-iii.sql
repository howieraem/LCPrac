/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        u.seller_id,
        COUNT(DISTINCT i.item_id) AS num_items
    FROM Users u
    JOIN Orders o ON u.seller_id = o.seller_id
    JOIN Items i ON o.item_id = i.item_id
    WHERE u.favorite_brand != i.item_brand
    GROUP BY u.seller_id
),
b AS (
    SELECT 
        seller_id, 
        num_items,
        DENSE_RANK() OVER (ORDER BY num_items DESC) AS rk
    FROM a
)
SELECT seller_id, num_items
FROM b
WHERE rk = 1
ORDER BY seller_id;