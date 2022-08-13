# Write your MySQL query statement below

# select p1.email as Email from  Person p1 ( select count(email) from Person  p2 where  p1.email = p2.email);

#Select count(email) from Person where count(email)>0 ; 


select email as Email from person group by email having count(email) > 1;