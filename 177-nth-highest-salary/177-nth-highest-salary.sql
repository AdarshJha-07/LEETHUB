CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
set n = n-1;
  RETURN (
      select distinct(salary) from Employee order by salary desc limit 1 offset n
  );
END