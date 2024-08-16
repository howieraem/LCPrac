SELECT 
    u.user_id AS buyer_id,
    u.join_date,
    IFNULL(o.cnt, 0) AS orders_in_2019
FROM Users u
LEFT JOIN (
    SELECT buyer_id, COUNT(order_id) AS cnt
    FROM Orders
    WHERE order_date between '2019-01-01' AND '2019-12-31'
    GROUP BY buyer_id
) o
ON u.user_id = o.buyer_id;