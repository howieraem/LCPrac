--
-- @lc app=leetcode id=1364 lang=mysql
--
-- [1364] Number of Trusted Contacts of a Customer
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    i.invoice_id,
    c1.customer_name,
    i.price,
    COUNT(Contacts.contact_name) AS contacts_cnt,
    COUNT(c2.customer_name) AS trusted_contacts_cnt
FROM Invoices i
INNER JOIN Customers c1 ON i.user_id = c1.customer_id
LEFT JOIN Contacts ON i.user_id = Contacts.user_id
LEFT JOIN Customers c2 ON Contacts.contact_email = c2.email
GROUP BY i.invoice_id, c1.customer_name, i.price
ORDER BY i.invoice_id;

-- @lc code=end

