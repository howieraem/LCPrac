--
-- @lc app=leetcode id=1543 lang=mysql
--
-- [1543] Fix Product Name Format
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    TRIM(LOWER(product_name)) AS product_name,
    DATE_FORMAT(sale_date, "%Y-%m") AS sale_date,
    COUNT(product_name) AS total
FROM Sales
GROUP BY 1, 2
ORDER BY 1, 2;

-- @lc code=end

