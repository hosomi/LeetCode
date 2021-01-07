SELECT 
  Department.Name AS Department
 ,EmployeeRank.Name AS Employee
 ,Salary
FROM
  (
    SELECT
      Name
     ,DepartmentId
     ,Salary
     ,DENSE_RANK() OVER (PARTITION BY DepartmentId ORDER BY Salary DESC) AS Rank
    FROM Employee
  ) EmployeeRank 
  INNER JOIN Department
  ON
  Department.Id = EmployeeRank.DepartmentId
WHERE Rank <= 3;
