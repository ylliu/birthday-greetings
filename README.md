# birthday-greeting-kata
Inital code:https://github.com/xpmatteo/birthday-greetings-kata.git    
refactoring step by step : https://github.com/trikitrok/BirthdayGreetingsKataStepByStep.git    

reference:https://martinfowler.com/articles/dipInTheWild.html     
http://garajeando.blogspot.com/2014/02/birthday-greetings-refactoring-kata-at.html  
 
### set boost env
in windows,set environment values    
set BOOST_ROOT to boost install path    
set BOOST_INCLUDEDIR also to boost install path   
set BOOST_LIBRARYDIR to boost lib directory   
eg.  
BOOST_ROOT = D:/DevelopmentEnviroment/boost_1_77_0  
BOOST_INCLUDEDIR = D:/DevelopmentEnviroment/boost_1_77_0  
BOOST_LIBRARYDIR = D:/DevelopmentEnviroment/boost_1_77_0/lib64-msvc-14.1   

### Init database postergresql
Create a database named postgres,and then create a table named employee,and then set fields,the fields are
id,last_name,first_name,date_of_birth and email.
The connect info is 
` "postgresql://postgres@localhost?port=5432&dbname=postgres&user=postgres&password=123456";`
```sql
-- Table: public.employee

-- DROP TABLE public.employee;

CREATE TABLE IF NOT EXISTS public.employee
(
    id integer NOT NULL,
    last_name character varying COLLATE pg_catalog."default" NOT NULL,
    first_name character varying COLLATE pg_catalog."default" NOT NULL,
    date_of_birth character varying COLLATE pg_catalog."default" NOT NULL,
    email character varying COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT employee_pkey PRIMARY KEY (id)
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.employee
    OWNER to postgres;
```





