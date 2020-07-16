--1) View  ce conţine o comandă SELECT pe o tabelă
CREATE VIEW vw_Angajat AS
       SELECT A.nume, A.pozitie
	   FROM Angajat as A

SELECT * FROM vw_Angajat

--2) View ce conţine o comandă SELECT pe o tabelă
CREATE VIEW vw_AngajatFiliala AS
SELECT A.nume, F.locatie 
FROM Angajat AS A INNER JOIN Filiala AS F
ON A.id_filiala = F.id_filiala

SELECT * FROM vw_AngajatFiliala

--3)View ce conţine o comandă SELECT aplicată pe cel puţin două tabele şi având o clauză GROUP BY.
ALTER VIEW vw_AngajatServicii AS
SELECT S.denumire AS [Nume serviciu] , SUM(M.id_angajat) AS [Numar angajati delegati]
FROM Servicii S INNER JOIN ServAng X ON S.id_servicii=X.id_servicii 
INNER JOIN Angajat M ON X.id_angajat = M.id_angajat
GROUP BY S.id_servicii,S.denumire

SELECT * FROM vw_AngajatServicii

---------PROCEDURI

--DELETE FROM 

ALTER PROCEDURE TestRun
( @test VARCHAR(50))
AS
BEGIN
	IF EXISTS (SELECT 1 FROM Tests WHERE Name = @test)
	BEGIN
	DECLARE @Curent DATETIME = GETDATE();
	INSERT INTO TestRuns
	VALUES ('First Test',@Curent,@Curent)

	DECLARE @TestRunID INT;
	
	DECLARE @tableName VARCHAR(30);
	DECLARE @q VARCHAR(100);


	SET @TestRunID = (SELECT TestRunId FROM TestRuns WHERE StartAt=@Curent);
	

	--Executam teste pe tabele


	--SELECT TOP 1 TestRunID FROM TestRunTables ORDER BY TestRunID DESC

	--DECLARE @N INT;
	
	--SET @N = (	SELECT TOP 1 TestRunID FROM TestRunTables ORDER BY TestRunID DESC)+1;
	--PRINT @N;

	--Stergerea
	SET @tableName = (SELECT T.Name FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 1)
	
	set @q = 'DELETE FROM ' + @tableName
	exec (@q)

	--DECLARE @tableName VARCHAR(30);
	--DECLARE @q VARCHAR(100);
	SET @tableName = (SELECT T.Name FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 2)
	
	set @q = 'DELETE FROM ' + @tableName
	exec (@q)

	SET @tableName = (SELECT T.Name FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 3)
	
	set @q = 'DELETE FROM ' + @tableName
	exec (@q)

	--INSERT INTO table_name VALUES (value1, value2,…);

	--DECLARE @tableName VARCHAR(30);
	--DECLARE @q VARCHAR(100);
	DECLARE @Id VARCHAR(50);
	DECLARE @Rows INT;

	DECLARE @ora DATETIME;

	DECLARE @tableId VARCHAR(30);
	SET @tableId = (SELECT T.TableID FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 3)
	SET @ora = GETDATE()
	INSERT INTO TestRunTables
	VALUES (@TestRunID,@tableId,@ora,@ora)
	---pozitia 3
	SET @Rows = (SELECT TT.NoOfRows FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 3)
	SET @Id = 1;
	WHILE @Rows > 0
	BEGIN
		SET @tableName = (SELECT T.Name FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 3)
		DECLARE @Name VARCHAR(50);
		Set @Name = '''Mihawk'''
		set @q = 'INSERT INTO ' + @tableName + '(id_client,nume)' +' VALUES('+@Id+','+ @Name + ')'
		PRINT @q
		exec (@q)
		--INSERT
		SET @Id = @Id + 1;
		SET @Rows = @Rows - 1;
	END 
	DECLARE @TestId INT;

	UPDATE TestRunTables 
	SET EndAt = GETDATE() WHERE
	StartAt = @ora

	---------
	SET @tableId = (SELECT T.TableID FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 2)
	SET @ora = GETDATE()
	INSERT INTO TestRunTables
	VALUES (@TestRunID,@tableId,@ora,@ora)
	---pozitia 2
	SET @Rows = (SELECT TT.NoOfRows FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 2)
	SET @Id = 1;
	WHILE @Rows > 0
	BEGIN
		SET @tableName = (SELECT T.Name FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 2)
		DECLARE @Model VARCHAR(50);
		Set @Model = '''Audi A5'''
		DECLARE @Motorizare VARCHAR(50);
		Set @Motorizare = '''3.0'''
		PRINT @Id
		set @q = 'INSERT INTO ' + @tableName + '(id_masina,model,motorizare,id_brand,stoc)' +' VALUES('+ @Id + ','+ @Model +',' + @Motorizare +',' + '1,10)'
		PRINT @q
		exec (@q)
		--INSERT
		SET @Id = @Id + 1;
		SET @Rows = @Rows - 1;
	END
	----------
	UPDATE TestRunTables 
	SET EndAt = GETDATE() WHERE
	StartAt = @ora
	----------
	SET @tableId = (SELECT T.TableID FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 1)
	SET @ora = GETDATE()
	INSERT INTO TestRunTables
	VALUES (@TestRunID,@tableId,@ora,@ora)
	---pozitia 1
	SET @Rows = (SELECT TT.NoOfRows FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 1)
	SET @Id = 1;
	WHILE @Rows > 0
	BEGIN
		SET @tableName = (SELECT T.Name FROM Tables T INNER JOIN TestTables TT ON T.TableID = TT.TableID WHERE TT.Position = 1)
		DECLARE @IdClient VARCHAR(50);
		SET @IdClient = 1;
		DECLARE @IdMasinaa VARCHAR(50);
		SET @IdMasinaa = 1;
		set @q = 'INSERT INTO ' + @tableName + '(id_client,id_masina)' +' VALUES('+ @Id + ',' + @Id + ')'
		PRINT @q
		exec (@q)
		--INSERT
		SET @Id = @Id + 1;
		SET @Rows = @Rows - 1;
	END
	-----------
	UPDATE TestRunTables 
	SET EndAt = GETDATE() WHERE
	StartAt = @ora
	-----------

	UPDATE TestRunTables 
	SET EndAt = GETDATE() WHERE
	StartAt = @Curent

	--------------------------------
	DECLARE @CurentViewTime DATETIME = GETDATE();

	-----------primul view
	SET @CurentViewTime  = GETDATE();
	INSERT INTO TestRunViews
	VALUES (@TestRunID,1,@CurentViewTime,@CurentViewTime)

	SELECT * FROM vw_Angajat

	UPDATE TestRunViews 
	SET EndAt = GETDATE() WHERE
	StartAt = @CurentViewTime
	----------
	--------al doilea view
	SET @CurentViewTime  = GETDATE();
	INSERT INTO TestRunViews
	VALUES (@TestRunID,2,@CurentViewTime,@CurentViewTime)

	SELECT * FROM vw_AngajatFiliala

	UPDATE TestRunViews 
	SET EndAt = GETDATE() WHERE
	StartAt = @CurentViewTime
	-------------
	---------al treilea view
	SET @CurentViewTime  = GETDATE();
	INSERT INTO TestRunViews
	VALUES (@TestRunID,3,@CurentViewTime,@CurentViewTime)
	SELECT * FROM vw_AngajatServicii

	UPDATE TestRunViews 
	SET EndAt = GETDATE() WHERE
	StartAt = @CurentViewTime
	----------------

	UPDATE TestRuns
	SET EndAt = GETDATE() WHERE
	StartAt = @Curent

	END

END
GO
EXEC TestRun First   

DELETE FROM TestRunViews
DELETE FROM TestRunTables
DELETE FROM TestRuns

SELECT * FROM TestRunViews
SELECT * FROM TestRunTables
SELECT * FROM TestRuns
