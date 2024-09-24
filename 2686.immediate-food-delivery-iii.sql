/* Write your T-SQL query statement below */
SELECT 
    order_date, 
    ROUND(
        SUM(
            CASE 
                WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 
            END) / CAST(COUNT(*) AS FLOAT) * 100, 
        2) AS immediate_percentage
FROM Delivery
GROUP BY order_date;
