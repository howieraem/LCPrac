CREATE PROCEDURE getUserIDs(@startDate DATE, @endDate DATE, @minAmount INT) AS
BEGIN
    /* Write your T-SQL query statement below. */
    SELECT DISTINCT user_id FROM Purchases
    WHERE time_stamp BETWEEN CAST(@startDate AS DATETIME) AND CAST(@endDate AS DATETIME)
    AND amount >= @minAmount
    ORDER BY user_id
END