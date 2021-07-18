/* Write your T-SQL query statement below */
SELECT Email
FROM
(
  SELECT
    Email
   ,COUNT(*) AS COUNT
  FROM Person
  GROUP BY Email
) AS InnerPerson
WHERE COUNT > 1
;
