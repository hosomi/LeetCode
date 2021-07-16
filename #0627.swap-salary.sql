/* Write your T-SQL query statement below */
UPDATE Salary SET sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex));
