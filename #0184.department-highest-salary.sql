/* Write your T-SQL query statement below */
WITH SalaryDepartmentMax AS (
  SELECT
    DepartmentId
   ,MAX(Salary) AS MaxSalary
  FROM Employee
  GROUP BY DepartmentId
)
SELECT
  D.Name AS Department
 ,E.Name AS Employee
 ,E.Salary
FROM
  Employee AS E
  INNER JOIN Department AS D
  ON E.DepartmentId = D.Id
  INNER JOIN SalaryDepartmentMax AS SDM
  ON
    E.DepartmentId = SDM.DepartmentId
    AND E.Salary = SDM.MaxSalary
