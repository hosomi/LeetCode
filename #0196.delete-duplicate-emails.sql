# Write your MySQL query statement below
DELETE p2
FROM
  Person AS p1 
  INNER JOIN Person AS p2
  ON p2.Email = p1.Email
WHERE p2.Id > p1.Id;
