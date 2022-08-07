CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
     
     Select distinct(e1.salary) from Employee e1 where (Select Count(Distinct e2.salary)=N-1 from Employee e2 where e2.salary>e1.salary)
  );
END