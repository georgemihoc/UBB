------------------------------
-----1)Dirty Reads Problem-----
------------------------------
CREATE PROCEDURE dirty_reads_problem2
AS
BEGIN
  SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
  BEGIN TRANSACTION
  SELECT * FROM Masina
  WAITFOR DELAY '00:00:15'
  SELECT * FROM Masina
  COMMIT TRANSACTION
END

EXEC dirty_reads_problem2

------------------------------
-----Dirty Reads Solution-----
------------------------------
CREATE PROCEDURE dirty_reads_solution2
AS
BEGIN
  SET TRANSACTION ISOLATION LEVEL READ COMMITTED
  BEGIN TRANSACTION
  SELECT * FROM Masina
  WAITFOR DELAY '00:00:15'
  SELECT * FROM Masina
  COMMIT TRANSACTION
END

EXEC dirty_reads_solution2


-----------------------------------------
-----2) Non-Repeatable Reads Problem-----
-----------------------------------------
CREATE PROCEDURE non_repeatable_reads_problem2
AS
BEGIN
  SET TRANSACTION ISOLATION LEVEL READ COMMITTED
  BEGIN TRANSACTION
  SELECT * FROM Masina
  WAITFOR DELAY '00:00:15'
  SELECT * FROM Masina
  COMMIT TRANSACTION
END

EXEC non_repeatable_reads_problem2

---------------------------------------
-----Non-Repeatable Reads Solution-----
---------------------------------------
CREATE PROCEDURE non_repeatable_reads_solution2
AS
BEGIN
  SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
  BEGIN TRANSACTION
  SELECT * FROM Masina
  WAITFOR DELAY '00:00:15'
  SELECT * FROM Masina
  COMMIT TRANSACTION
END

EXEC non_repeatable_reads_solution2


------------------------------------
-----3) Phantom Reads Problem-------
------------------------------------
CREATE PROCEDURE phantom_reads_problem2
AS
BEGIN
  SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
  BEGIN TRANSACTION
  SELECT * FROM Masina
  WAITFOR DELAY '00:00:15'
  SELECT * FROM Masina
  COMMIT TRANSACTION
END

EXEC phantom_reads_problem2

--------------------------------
-----Phantom Reads Solution-----
--------------------------------
CREATE PROCEDURE phantom_reads_solution2
AS
BEGIN
  SET TRANSACTION ISOLATION LEVEL SERIALIZABLE
  BEGIN TRANSACTION
  SELECT * FROM Masina
  WAITFOR DELAY '00:00:15'
  SELECT * FROM Masina
  COMMIT TRANSACTION
END

EXEC phantom_reads_solution2


-------------------------------
-----4) Deadlock Problem-------
-------------------------------
CREATE PROCEDURE deadlock_problem2
AS
BEGIN
  BEGIN TRANSACTION
    BEGIN TRY
      UPDATE Servicii SET pret=600 WHERE denumire='inchiriere'
      INSERT INTO LogTable VALUES ('Deadlock Problem first update 2','Servicii',SYSDATETIME())
      WAITFOR DELAY '00:00:10'
      UPDATE Masina SET stoc=7 WHERE model='M6'
      INSERT INTO LogTable VALUES ('Deadlock Problem first update 2','Masina',SYSDATETIME())
    COMMIT TRANSACTION
  END TRY
  BEGIN CATCH
    ROLLBACK TRANSACTION
    INSERT INTO LogTable VALUES ('Deadlock','Masina Servicii',SYSDATETIME())
  END CATCH
END

EXEC deadlock_problem2

---------------------------
-----Deadlock Solution-----
---------------------------
CREATE PROCEDURE deadlock_solution2
AS
BEGIN
  SET DEADLOCK_PRIORITY HIGH
  BEGIN TRANSACTION
    BEGIN TRY
      UPDATE Servicii SET pret=600 WHERE denumire='inchiriere'
      INSERT INTO LogTable VALUES ('Deadlock Solution first update 2','Servicii',SYSDATETIME())
      WAITFOR DELAY '00:00:10'
      UPDATE Masina SET stoc=7 WHERE model='M6'
      INSERT INTO LogTable VALUES ('Deadlock Solution update 2','Masina',SYSDATETIME())
    COMMIT TRANSACTION
  END TRY
  BEGIN CATCH
    ROLLBACK TRANSACTION
    INSERT INTO LogTable VALUES ('Deadlock','Masina Servicii',SYSDATETIME())
  END CATCH
END

EXEC deadlock_solution2
