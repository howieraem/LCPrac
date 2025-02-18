--
-- @lc app=leetcode id=1384 lang=mysql
--
-- [1384] Total Sales Amount by Year
--

-- @lc code=start
/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT 
        product_id, '2018' AS report_year,
        CASE
            WHEN YEAR(period_start) = '2018' AND YEAR(period_end) = '2018' THEN (DATEDIFF(DAY, period_start, period_end) + 1) * average_daily_sales
            WHEN YEAR(period_start) = '2018' AND YEAR(period_end) != '2018' THEN (DATEDIFF(DAY, period_start, '2018-12-31') + 1) * average_daily_sales
            WHEN YEAR(period_start) != '2018' AND YEAR(period_end) = '2018' THEN (DATEDIFF(DAY, '2018-01-01', period_end) + 1) * average_daily_sales
            ELSE (DATEDIFF(DAY, '2018-01-01', '2018-12-31') + 1) * average_daily_sales
        END AS total_amount
    FROM Sales
    WHERE '2018' BETWEEN YEAR(period_start) AND YEAR(period_end)
    UNION
    SELECT 
        product_id, '2019' AS report_year,
        CASE
            WHEN YEAR(period_start) = '2019' AND YEAR(period_end) = '2019' THEN (DATEDIFF(DAY, period_start, period_end) + 1) * average_daily_sales
            WHEN YEAR(period_start) = '2019' AND YEAR(period_end) != '2019' THEN (DATEDIFF(DAY, period_start, '2019-12-31') + 1) * average_daily_sales
            WHEN YEAR(period_start) != '2019' AND YEAR(period_end) = '2019' THEN (DATEDIFF(DAY, '2019-01-01', period_end) + 1) * average_daily_sales
            ELSE (DATEDIFF(DAY, '2019-01-01', '2019-12-31') + 1) * average_daily_sales
        END AS total_amount
    FROM Sales
    WHERE '2019' BETWEEN YEAR(period_start) AND YEAR(period_end)
    UNION
    SELECT 
        product_id, '2020' AS report_year,
        CASE
            WHEN YEAR(period_start) = '2020' AND YEAR(period_end) = '2020' THEN (DATEDIFF(DAY, period_start, period_end) + 1) * average_daily_sales
            WHEN YEAR(period_start) = '2020' AND YEAR(period_end) != '2020' THEN (DATEDIFF(DAY, period_start, '2020-12-31') + 1) * average_daily_sales
            WHEN YEAR(period_start) != '2020' AND YEAR(period_end) = '2020' THEN (DATEDIFF(DAY, '2020-01-01', period_end) + 1) * average_daily_sales
            ELSE (DATEDIFF(DAY, '2020-01-01', '2020-12-31') + 1) * average_daily_sales
        END AS total_amount
    FROM Sales
    WHERE '2020' BETWEEN YEAR(period_start) AND YEAR(period_end)
)
SELECT p.product_id, p.product_name, cte.report_year, cte.total_amount
FROM Product p
JOIN cte ON p.product_id = cte.product_id
ORDER BY p.product_id, cte.report_year;

-- @lc code=end

