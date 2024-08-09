SELECT 
    ad_id,
    ROUND(IFNULL(SUM(CASE WHEN `action` = 'Clicked' THEN 1.0 ELSE 0.0 END) / SUM(CASE WHEN `action` != 'Ignored' THEN 1.0 ELSE 0.0 END) * 100.0, 0.0), 2) AS ctr
FROM Ads
GROUP BY ad_id
ORDER BY ctr DESC, ad_id;