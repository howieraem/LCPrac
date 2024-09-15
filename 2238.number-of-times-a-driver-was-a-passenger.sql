SELECT a.driver_id, COUNT(DISTINCT b.ride_id) AS cnt
FROM Rides a
LEFT JOIN Rides b  -- need to show all drivers even some have never been passengers
    ON a.driver_id = b.passenger_id
GROUP BY a.driver_id;
