
create table students (username varchar, password varchar, enabled int, role varchar);

create table questions (id int not null identity(1,1), text varchar, correctAnswer varchar);