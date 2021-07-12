CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
  DECLARE @Offset INT = @N - 1;
  RETURN (
      -- Write your T-SQL query statement below.
      SELECT Salary 
      FROM Employee  
      GROUP BY Salary
      ORDER BY Salary DESC
      OFFSET (@Offset) ROWS FETCH NEXT 1 ROWS ONLY
  );
END
