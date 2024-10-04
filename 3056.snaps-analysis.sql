/* Write your T-SQL query statement below */
SELECT
    age_bucket,
    ROUND(SUM(IIF(activity_type = 'send', time_spent, 0)) * 100.0 / SUM(time_spent), 2) AS send_perc,
    ROUND(SUM(IIF(activity_type = 'open', time_spent, 0)) * 100.0 / SUM(time_spent), 2) AS open_perc
FROM Activities a1
LEFT JOIN Age a2 ON a1.user_id = a2.user_id
GROUP BY age_bucket; 
