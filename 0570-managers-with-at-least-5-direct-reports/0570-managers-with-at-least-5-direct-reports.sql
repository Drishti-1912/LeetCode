# Write your MySQL query statement below
SELECT e1.name from Employee e1
INNER Join Employee e2 
ON e1.id=e2.managerId 
Group By e2.managerId 
HAVING COUNT(e2.managerId)>=5