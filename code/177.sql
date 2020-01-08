# Write your MySQL query statement below
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      
  );
END
SELECT 
(SELECT DISTINCT Salary
FROM Employee
ORDER BY Salary DESC
LIMIT 1, 1) AS SecondHighestSalary