--
-- @lc app=leetcode id=1677 lang=mysql
--
-- [1677] Product's Worth Over Invoices
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    p.name,
    IFNULL(SUM(i.rest), 0) AS rest,
    IFNULL(SUM(i.paid), 0) AS paid,
    IFNULL(SUM(i.canceled), 0) AS canceled,
    IFNULL(SUM(i.refunded), 0) AS refunded
FROM Product p
LEFT JOIN Invoice i -- we want all products even though some are absent in the invoice table
ON p.product_id = i.product_id
GROUP BY 1
ORDER BY 1;

-- @lc code=end

