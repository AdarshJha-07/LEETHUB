
Select name ,sum(ifnull(distance,0)) as travelled_distance from  Users  u left join Rides r on
r.user_id = u.id  group  by r.user_id order by sum(distance) desc ,name ;