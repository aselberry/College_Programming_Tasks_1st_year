--List the name, address, and tax number of mechanics who have ever had a salary less than that of all mechanics who have ever worked for the 
--workshop named 'Harmat Kft.' Each mechanic should appear only once in the result. 

SELECT DISTINCT m_name, tax_number, address
    FROM CARMECHANIC.m_mechanic mm 
    JOIN carmechanic.m_works_for wf 
    ON mm.m_id = wf.mechanic_id
    where salary < ALL(select salary from carmechanic.m_workshop mw
                    JOIN carmechanic.m_works_for mf
                    ON mw.w_id=mf.workshop_id
                    where mw.w_name like 'Harmat Kft.');
_______________________________________________________
--List the licence plate number of cars having a repair with a cost less than any repair cost of a Suzuki car. 
--Each license plate number should appear only once in the result

SELECT DISTINCT license_plate_number
    FROM CARMECHANIC.m_car mc 
    JOIN carmechanic.m_repair mr ON mc.c_id=mr.car_id
    WHERE repair_cost < (SELECT MIN(repair_cost)
                        FROM CARMECHANIC.m_repair rm
                        JOIN CARMECHANIC.m_car cm ON rm.car_id=cm.c_id
                        JOIN carmechanic.m_car_model mcm
                        ON cm.model_id=mcm.cm_id
                        where make like 'Suzuki');
                        
___________________________________________________________
--List all data of cars that have never been evaluated

SELECT * FROM 
    CARMECHANIC.m_car mc LEFT JOIN 
    CARMECHANIC.m_car_evaluation me ON mc.c_id=me.car_id
    where car_id is NULL;
    
____________________________________________________________
--List the license number of cars participating in the  evaluation with the 10 lowest evaluation prices. Also 
--give the evaluation prices along with the license plate numbers. Sort the list descending by evaluation price. 

SELECT license_plate_number, price
    FROM CARMECHANIC.m_car mc JOIN
    CARMECHANIC.m_car_evaluation me ON mc.c_id=me.car_id
    where car_id in (select car_id
                        FROM CARMECHANIC.m_car_evaluation
                        order by price ASC
                        fetch first 10 rows with ties)
    ORDER BY price DESC;
    

_________________________________________________________________
--Creating Table (The details were given by the professor)

CREATE TABLE work_plan2
(
    workday2 date DEFAULT sysdate,
    mechanic2 number(5),
    workshop2 number(5),
    constraint work2_fk1 FOREIGN KEY (mechanic2) references m_mechanic (m_id),
    CONSTRAINT work2_fk2 FOREIGN KEY (workshop2) references m_workshop (w_id).
    constraint work2_pk primary KEY (workday2, mechanic2)
);

_________________________________________________________________
--List the average evaluation price for cars of each model where this average is one of the lowest three. The models 
--should be represented in the result by their identifiers.

SELECT model_id, AVG(price) from CARMECHANIC.m_car_evaluation mce
    JOIN CARMECHANIC.m_car mc ON mce.car_id=mc.c_id
    GROUP by model_id
    ORDER by avg(price) ASC
    fetch first 3 rows with ties;

____________________________________________________________________
--The workshop named 'Kerekes Alex Szervize' is closing down (you may assume that there is only one workshop
--with that name.) Delete the employment of all

select mechanic_id, w_id, end_of_employment, w_name from 
    carmechanic.m_works_for JOIN carmechanic.m_workshop
    ON workshop_id=w_id
    where w_name = 'Kerekes Alex Szervize';

____________________________________________________________________
--Decrease the repair cost of the red and the black cars by 10% of the car`s first_sell_price. If the first sell
--price is unknown, the repair cost should be unchanged

update m_repair
    set repair_cost = repair_cost - 0.1*(select first_sell_price from carmechanic.m_car where c_id=m_repair.car_id)
    where car_id in(select c_id from 
                    carmechanic.m_car 
                    where color in ('red', 'black'));

________________________________________________________________________-
--Create a view that shows the name of the workshop where the longest  (finished) repair took place, together with the duration of this repair in days

create view test6 as
    select w_name, max(end_date - start_date) longest_day
        from carmechanic.m_repair mr
        JOIN carmechanic.m_workshop mw
        ON mr.workshop_id = mw.w_id 
        GROUP by w_name, w_id
        ORDER by max(end_date - start_date) desc
        FETCH FIRST ROW WITH TIES;
________________________________________________________________________________
 --Create a view that shows the year(s) for which the most evaluations of cars with this first-sell year took place
 
 create view most_evaluation as 
    select first_sell_date, count(price) 
        from carmechanic.m_car mc JOIN carmechanic.m_car_evaluation mce
        ON mc.c_id=mce.car_id
        group by first_sell_date, c_id
        order by count (price)desc
        fetch first row with ties;

