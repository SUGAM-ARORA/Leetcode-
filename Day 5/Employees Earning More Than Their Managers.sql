# Write your MySQL query statement below
SELECT
     x.NAME AS Employee
FROM Employee AS x JOIN Employee AS y
     ON x.ManagerId = y.Id
     AND x.Salary > y.Salary
