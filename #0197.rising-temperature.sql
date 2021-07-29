/* Write your T-SQL query statement below */
SELECT W2.id
FROM
  Weather AS W1
  INNER JOIN Weather AS W2
  ON W1.recordDate = DATEADD(day,-1, W2.recordDate)
WHERE W2.temperature > W1.temperature
