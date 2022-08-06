# Write your MySQL query statement below

  Select Max(Salary) as SecondHighestSalary from Employee   where Salary Not IN  (Select Max(salary) from Employee );
  
# select IFNULL(NULL, select salary as SecondHighestSalary from Employee order by salary desc limit 1 offset 1);

# SELECT DISTINCT
#     Salary AS SecondHighestSalary
# FROM
#     Employee
# ORDER BY Salary DESC
# LIMIT 1 OFFSET 1