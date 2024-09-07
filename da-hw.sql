-- Table: recordId, serverId, date, repairStatus {'start', 'end'}
-- Calculate the total days of repair for each server

-- INIT database
CREATE TABLE Maintenance (
  recordId INT IDENTITY(1, 1),
  serverId INT,
  date DATE,
  repairStatus VARCHAR(50)
);

INSERT INTO MaintenanceRecords(serverId, date, repairStatus) VALUES (1, '2020-01-02', 'start');
INSERT INTO MaintenanceRecords(serverId, date, repairStatus) VALUES (1, '2020-01-05', 'end');
INSERT INTO MaintenanceRecords(serverId, date, repairStatus) VALUES (2, '2020-01-02', 'start');
INSERT INTO MaintenanceRecords(serverId, date, repairStatus) VALUES (2, '2020-01-03', 'end');
INSERT INTO MaintenanceRecords(serverId, date, repairStatus) VALUES (1, '2020-01-10', 'start');
INSERT INTO MaintenanceRecords(serverId, date, repairStatus) VALUES (1, '2020-01-12', 'end');

-- Solution 1: LEAD/LAG
WITH t AS (
    SELECT 
        serverId, 
        date AS startDate, 
        LEAD(date) OVER (PARTITION BY serverId ORDER BY date) AS endDate,
        repairStatus
    FROM MaintenanceRecords
)
SELECT 
    serverId,
    SUM(DATEDIFF(DAY, startDate, COALESCE(endDate, GETDATE()))) AS repairDays
FROM t
WHERE repairStatus = 'start' AND endDate IS NOT NULL
GROUP BY serverId;

-- Solution 2: Self-join
WITH repair_date AS (
   SELECT
       ServerID,
       Date AS repair_date,
       RepairStatus,
       ROW_NUMBER() OVER (PARTITION BY ServerID ORDER BY Date ASC) AS rr
   FROM
       MaintenanceRecords
   WHERE
       RepairStatus = 'start'
),
online_date AS (
   SELECT
       ServerID,
       Date AS online_date,
       RepairStatus,
       ROW_NUMBER() OVER (PARTITION BY ServerID ORDER BY Date ASC) AS rr
   FROM
       MaintenanceRecords
   WHERE
       RepairStatus = 'end'
),
result_table AS (
   SELECT
       a.ServerID,
       a.RepairStatus AS repair_repair_status,
       a.repair_date,
       b.RepairStatus AS online_repair_status,
       ISNULL(b.online_date, GETDATE()) AS online_date,
       DATEDIFF(day, a.repair_date, ISNULL(b.online_date, GETDATE())) AS days_of_repair
   FROM
       repair_date a
   LEFT JOIN
       online_date b
   ON
       a.ServerID = b.ServerID AND a.rr = b.rr
)
SELECT
   ServerID,
   SUM(days_of_repair) AS total_days_of_repair
FROM
   result_table
GROUP BY
   ServerID;


-- Solution 3: without LEAD/LAG, without self-join
WITH t1 AS (
   SELECT
       ServerID,
       Date,
       RepairStatus,
       DATEDIFF(DAY, date, GETDATE()) AS days_of_repair,
       CASE WHEN RepairStatus = 'start' THEN 1 ELSE -1 END AS factor
   FROM
       MaintenanceRecords
)
SELECT
   ServerID,
   SUM(days_of_repair * factor) AS total_days_of_repair
FROM
   t1
GROUP BY
   ServerID;

