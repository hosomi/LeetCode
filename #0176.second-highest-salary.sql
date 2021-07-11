# Write your MySQL query statement below
WITH MAX_Salary AS (
    SELECT MAX(Salary) AS "MaxSalary"
    FROM Employee
)
SELECT MAX(Salary) AS "SecondHighestSalary"
FROM Employee
WHERE Salary < (SELECT MaxSalary FROM MAX_Salary)
