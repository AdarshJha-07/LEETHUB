CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      Select  distinct e1.salary from Employee as e1 where N-1 = (select Count(Distinct salary) from Employee as e2 where e2.salary>e1.salary)
      # select distinct e1.salary from Employee e1 where N-1 = (select count(distinct e2.Salary) from Employee e2 where e1.Salary < e2.Salary)
  );
END