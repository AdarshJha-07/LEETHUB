# Write your MySQL query statement below

# SELECT  class from Courses c1 (Select count(class) from Courses where count(c1.class)>=5);

 Select  class from Courses group by class having count(class)>=5;