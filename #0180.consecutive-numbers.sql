/* Write your T-SQL query statement below */
SELECT DISTINCT l1.Num AS ConsecutiveNums 
FROM
  Logs AS L1
  INNER JOIN Logs AS L2
  ON L1.Num = L2.Num 
  AND L1.Id = L2.Id - 1
  INNER JOIN Logs AS L3
  ON L2.Num = L3.Num
  AND L2.Id = L3.Id - 1
;
