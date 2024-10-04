/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        DISTINCT state, 
        PERCENTILE_DISC(0.05) WITHIN GROUP (ORDER BY fraud_score DESC) OVER (PARTITION BY state) AS p95_score
    FROM Fraud
)
SELECT b.policy_id, b.state, b.fraud_score
FROM Fraud b
JOIN a ON b.state = a.state
WHERE b.fraud_score >= a.p95_score
ORDER BY b.state, b.fraud_score DESC, b.policy_id
