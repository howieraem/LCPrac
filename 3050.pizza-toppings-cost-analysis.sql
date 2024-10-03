/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        t1.topping_name + ',' + t2.topping_name + ',' + t3.topping_name AS pizza,
        ROUND(t1.cost + t2.cost + t3.cost, 2) AS total_cost
    FROM Toppings t1
    JOIN Toppings t2 ON t1.topping_name < t2.topping_name
    JOIN Toppings t3 ON t2.topping_name < t3.topping_name
)
SELECT pizza, total_cost
FROM a
ORDER BY total_cost DESC, pizza