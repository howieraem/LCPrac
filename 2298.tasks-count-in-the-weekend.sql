/* Write your T-SQL query statement below */
SELECT
    SUM(
        CASE 
            WHEN DATEPART(WEEKDAY,submit_date) = 1 OR DATEPART(WEEKDAY,submit_date) = 7 THEN 1 
            ELSE 0 
        END) AS weekend_cnt,
    SUM(
        CASE 
            WHEN DATEPART(WEEKDAY,submit_date) != 1 AND DATEPART(WEEKDAY,submit_date) != 7 THEN 1 
            ELSE 0 
        END) AS working_cnt
FROM Tasks