# Write your MySQL query statement below

# Select d1.name ,e1.name, Max(e1.salary) from Employee as e1 left join Department as d1 on  e1.id = d1.id  group by d1.id

# Select Department.Name, emp1.Name, emp1.Salary from 
# Employee emp1 join Department on emp1.DepartmentId = Department.Id
# where emp1.Salary = (Select Max(Salary) from Employee emp2 where emp2.DepartmentId = emp1.DepartmentId);

select Department.name as Department ,Employee.name as Employee ,Employee.salary as Salary from Employee join Department on Employee.departmentId = Department.id where(Employee.departmentId,Employee.salary) IN
(select Departmentid,max(salary) from Employee group by departmentId);