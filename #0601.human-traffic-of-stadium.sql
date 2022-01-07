/* Write your T-SQL query statement below */
WITH ThreeDay AS (
  SELECT 
    *
   ,lead(people, 1, NULL) over (order by id) AS next1
   ,lead(people, 2, NULl) over (order by id) AS next2 
  FROM Stadium
)
,Ids AS (
  SELECT id 
  FROM ThreeDay
  WHERE 
    people >= 100
    AND next1 >= 100
    AND next2 >= 100

  UNION ALL

  SELECT id + 1
  FROM ThreeDay
  WHERE 
    people >= 100 
    AND next1 >= 100 
    AND next2 >= 100

  UNION ALL

  SELECT id + 2
  FROM ThreeDay
  WHERE
    people >= 100
    AND next1 >= 100
    AND next2 >= 100
)
SELECT * 
FROM Stadium
WHERE id in (SELECT * FROM Ids);
