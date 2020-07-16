--------------------
--Create Log Table--
--------------------
ALTER TABLE LogTable(
	Lid INT IDENTITY PRIMARY KEY,
	TypeOperation VARCHAR(50),
	TableOperation VARCHAR(50),
	ExecutionDate DATETIME
)
GO

DELETE FROM LogTable


------------------------------
------Create Dirty Reads------
------------------------------
CREATE PROCEDURE dirty_reads_problem1
AS
BEGIN
  BEGIN TRANSACTION
  UPDATE Masina SET model = 's4' WHERE id_masina = 1
  INSERT INTO LogTable VALUES ('Dirty Reads Problem','Masina',SYSDATETIME())
  WAITFOR DELAY '00:00:10'
  ROLLBACK TRANSACTION
END

CREATE PROCEDURE dirty_reads_solution1
AS
BEGIN
  BEGIN TRANSACTION
  UPDATE Masina SET model = 's4' WHERE id_masina = 1
  INSERT INTO LogTable VALUES ('Dirty Reads Solution','Masina',SYSDATETIME())
  WAITFOR DELAY '00:00:10'
  ROLLBACK TRANSACTION
END

-- Problem
EXEC dirty_reads_problem1
EXEC dirty_reads_problem2
SELECT * FROM Masina

-- Solution
EXEC dirty_reads_solution1
EXEC dirty_reads_solution2
SELECT * FROM Masina


---------------------------------------
------Create Non-Repeatable Reads------
---------------------------------------
CREATE PROCEDURE non_repeatable_reads_problem1
AS
BEGIN
  INSERT INTO Masina VALUES ('M6','4.4',1,3)
  INSERT INTO LogTable VALUES ('Non-Repeatable Reads Problem at insert','Masina',SYSDATETIME())
  BEGIN TRANSACTION
  WAITFOR DELAY '00:00:10'
  UPDATE Masina SET stoc=5 WHERE model='M6'
  INSERT INTO LogTable VALUES ('Non-Repeatable Reads Problem at update','Masina',SYSDATETIME())
  COMMIT TRANSACTION
END

CREATE PROCEDURE non_repeatable_reads_solution1
AS
BEGIN
  INSERT INTO Masina VALUES ('M6','4.4',1,3)
  INSERT INTO LogTable VALUES ('Non-Repeatable Reads Solution at insert','Masina',SYSDATETIME())
  BEGIN TRANSACTION
  WAITFOR DELAY '00:00:10'
  UPDATE Masina SET stoc=5 WHERE model='M6'
  INSERT INTO LogTable VALUES ('Non-Repeatable Reads Solution at update','Masina',SYSDATETIME())
  COMMIT TRANSACTION
END

-- Problem
EXEC non_repeatable_reads_problem1
EXEC non_repeatable_reads_problem2
SELECT * FROM Masina

-- Solution
EXEC non_repeatable_reads_solution1
EXEC non_repeatable_reads_solution2
SELECT * FROM Masina


--------------------------------
------Create Phantom Reads------
--------------------------------
CREATE PROCEDURE phantom_reads_problem1
AS
BEGIN
  BEGIN TRANSACTION
  WAITFOR DELAY '00:00:10'
  INSERT INTO Masina VALUES ('M760Li','6.6',1,1)
  INSERT INTO LogTable VALUES ('Phantom Reads Problem','Masina',SYSDATETIME())
  COMMIT TRANSACTION
END

CREATE PROCEDURE phantom_reads_solution1
AS
BEGIN
  BEGIN TRANSACTION
  WAITFOR DELAY '00:00:10'
  INSERT INTO Masina VALUES ('M760Li','6.6',1,1)
  INSERT INTO LogTable VALUES ('Phantom Reads Solution','Masina',SYSDATETIME())
  COMMIT TRANSACTION
END

-- Problem
EXEC phantom_reads_problem1
EXEC phantom_reads_problem2
SELECT * FROM Masina


-- Solution
EXEC phantom_reads_solution1
EXEC phantom_reads_solution2
SELECT * FROM Masina


--------------------------------
--------Create Deadlock---------
--------------------------------
CREATE PROCEDURE deadlock_problem1
AS
BEGIN
  BEGIN TRANSACTION
    BEGIN TRY
      UPDATE Masina SET stoc=6 WHERE model='M6'
      INSERT INTO LogTable VALUES ('Deadlock Problem first update 1','Masina',SYSDATETIME())
      WAITFOR DELAY '00:00:10'
      UPDATE  Servicii SET pret=500 WHERE denumire='inchiriere'
      INSERT INTO LogTable VALUES ('Deadlock Problem second update 1','Servicii',SYSDATETIME())
    COMMIT TRANSACTION
  END TRY
  BEGIN CATCH
    ROLLBACK TRANSACTION
    INSERT INTO LogTable VALUES ('Deadlock 1','Masina Servicii',SYSDATETIME())
  END CATCH
END

CREATE PROCEDURE deadlock_solution1
AS
BEGIN
  BEGIN TRANSACTION
    BEGIN TRY
      UPDATE Masina SET stoc=6 WHERE model='M6'
      INSERT INTO LogTable VALUES ('Deadlock Problem first update 1','Masina',SYSDATETIME())
      WAITFOR DELAY '00:00:10'
      UPDATE  Servicii SET pret=500 WHERE denumire='inchiriere'
      INSERT INTO LogTable VALUES ('Deadlock Problem second update 1','Servicii',SYSDATETIME())
    COMMIT TRANSACTION
  END TRY
  BEGIN CATCH
    ROLLBACK TRANSACTION
    INSERT INTO LogTable VALUES ('Deadlock 1','Masina Servicii',SYSDATETIME())
  END CATCH
END

-- Problem
EXEC deadlock_problem1
EXEC deadlock_problem2
SELECT * FROM Masina
SELECT * FROM Servicii


-- Solution
EXEC deadlock_solution1
EXEC deadlock_solution2
SELECT * FROM Masina
SELECT * FROM Servicii
