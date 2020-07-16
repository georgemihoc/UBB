 
------------------------------------
----------1)TABEL Client--------------
------------------------------------

--procedura de adaugare client
ALTER PROCEDURE addClient 
(@id_client INT,
@nume VARCHAR(50),
@return INT OUTPUT)
AS
BEGIN
	IF dbo.checknume(@nume) = 0 or dbo.checknume(@nume) > 10
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	BEGIN TRY 
		INSERT INTO Client VALUES ( @id_client, @nume);
		SET @return = 1;
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnAddClient AS INT
EXEC addClient 13,'Victor', @returnAddClient OUTPUT;
PRINT @returnAddClient;

--procedura de stergere client
ALTER PROCEDURE deleteClient 
(@id_client INT,
@return INT OUTPUT)
AS
BEGIN
		DECLARE @ok INT;
		SET @ok = ( SELECT COUNT (id_client) FROM ClMas WHERE @id_client=id_client)
		IF @ok != 0 
		BEGIN
			PRINT 'Nu se poate efectua stergerea'
			RETURN
		END

		DECLARE @before INT;
		SET @before =( SELECT COUNT (id_client) FROM Client); 
		DELETE FROM Client WHERE @id_client = id_client 
		--DELETE FROM ClMas WHERE id_client = @id_client
		DECLARE @after INT;
		SET @after =( SELECT COUNT (id_client) FROM Client);
		IF @after != @before
		BEGIN
			SET @return = 1;
			RETURN
		END
		SET @return = 0;
END;

DECLARE @returnDeleteClient AS INT
EXEC deleteClient 13,@returnDeleteClient OUTPUT;
PRINT @returnDeleteClient;

--procedura de update client
ALTER PROCEDURE updateClient 
(@id_client INT,
@nume VARCHAR(50),
@return INT OUTPUT)
AS
BEGIN
	IF dbo.checknume(@nume) = 0 or dbo.checknume(@nume) > 10
	BEGIN 
		SET @return = 0;
		RETURN;
	END

	DECLARE @returnSelectClient AS INT
	SET @returnSelectClient = (SELECT COUNT (*) FROM Client where id_client= @id_client);
	IF @returnSelectClient = 0
	BEGIN 
	SET @return = 0;
		RETURN;
	END

	BEGIN TRY 
		UPDATE Client
			SET nume = @nume WHERE
			id_client = @id_client
		SET @return = 1;
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnUpdateClient AS INT
EXEC updateClient 11,'victor', @returnUpdateClient OUTPUT;
PRINT @returnUpdateClient;

--procedura de select client
ALTER PROCEDURE selectClient 
(@id_client INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @rez INT;
	SET @rez = (SELECT COUNT (*) FROM Client where id_client= @id_client);
	IF @rez = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	SET @return = 1;
	SELECT * FROM Client where id_client= @id_client
END;

DECLARE @returnSelectClient AS INT
EXEC selectClient 1, @returnSelectClient OUTPUT;
PRINT @returnSelectClient;

--Functie care testeaza numele unui client
CREATE FUNCTION checknume(@nume VARCHAR(30))
RETURNS INT AS
BEGIN
	DECLARE @length INT;
	SET @length = LEN(@nume);
	RETURN @length;
END;
PRINT dbo.checknume('alex');


------------------------------------
----------2)TABEL ClMas--------------
------------------------------------

--procedura de adaugare clmas
ALTER PROCEDURE addClMas 
(@id_client INT,
@id_masina INT,
@return INT OUTPUT)
AS
BEGIN

	DECLARE @returnSelectClient AS INT
	SET @returnSelectClient = (SELECT COUNT (*) FROM Client where id_client= @id_client);

	DECLARE @returnSelectMasina AS INT
	SET @returnSelectMasina = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina);

	IF @returnSelectClient = 1 and @returnSelectMasina = 1
	BEGIN
		BEGIN TRY 
			INSERT INTO ClMas VALUES ( @id_client, @id_masina);
			SET @return = 1;
			RETURN @return;
		END TRY
		BEGIN CATCH 
			SET @return = 0;
		END CATCH
	END
	SET @return = 0;
	RETURN @return;
END;

DECLARE @returnAddClMas AS INT
EXEC addClMas 11,1, @returnAddClMas OUTPUT;
PRINT @returnAddClMas;

--procedura de stergere clmas
CREATE PROCEDURE deleteClMas 
(@id_client INT,
@id_masina INT,
@return INT OUTPUT)
AS
BEGIN
		DECLARE @before INT;
		SET @before =( SELECT COUNT (id_client) FROM ClMas); 
		DELETE FROM ClMas WHERE @id_client = id_client AND @id_masina = @id_masina
		DECLARE @after INT;
		SET @after =( SELECT COUNT (id_client) FROM ClMas);
		IF @after != @before
		BEGIN
			SET @return = 1;
			RETURN
		END
		SET @return = 0;
END;

DECLARE @returnDeleteClMas AS INT
EXEC deleteClMas 11, 3,@returnDeleteClMas OUTPUT;
PRINT @returnDeleteClMas;

--procedura de update clmas
CREATE PROCEDURE updateClMas 
(@id_client1 INT,
@id_masina1 INT,
@id_client2 INT,
@id_masina2 INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @returnSelectClient1 AS INT
	SET @returnSelectClient1 = (SELECT COUNT (*) FROM Client where id_client= @id_client1);

	DECLARE @returnSelectMasina1 AS INT
	SET @returnSelectMasina1 = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina1);

	DECLARE @returnSelectClient2 AS INT
	SET @returnSelectClient2 = (SELECT COUNT (*) FROM Client where id_client= @id_client2);

	DECLARE @returnSelectMasina2 AS INT
	SET @returnSelectMasina2 = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina2);

	IF @returnSelectClient1 = 0 or @returnSelectMasina1 = 0 or @returnSelectClient2 = 0 or @returnSelectMasina2 = 0
	BEGIN 
		SET @return = 0;
		RETURN @return;
	END
	BEGIN TRY 
		INSERT INTO ClMas VALUES ( @id_client2, @id_masina2);
		DELETE FROM ClMas WHERE id_client = @id_client1 and id_masina = @id_masina1
		SET @return = 1;
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnUpdateClMas AS INT
EXEC updateClMas 11,1, 11,3, @returnUpdateClMas OUTPUT;
PRINT @returnUpdateClMas;

--procedura de select ClMas
CREATE PROCEDURE selectClMas 
(@id_client INT,
@id_masina INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @rez INT;
	SET @rez = (SELECT COUNT (*) FROM ClMas where id_client= @id_client and id_masina = @id_masina);
	IF @rez = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	SET @return = 1;
	SELECT * FROM ClMas where id_client= @id_client and id_masina = @id_masina
END;

DECLARE @returnSelectClMas AS INT
EXEC selectClMas 10,10, @returnSelectClMas OUTPUT;
PRINT @returnSelectClMas;


------------------------------------
----------3)TABEL Masina--------------
------------------------------------

--procedura de adaugare masina
ALTER PROCEDURE addMasina 
(@id_masina INT,
@model VARCHAR(50),
@motorizare VARCHAR(50),
@id_brand INT,
@stoc INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @returnSelectBrand AS INT
	SET @returnSelectBrand = (SELECT COUNT (*) FROM Brand where id_brand= @id_brand);

	IF dbo.checkModel(@model) = 0 or @returnSelectBrand = 0 or dbo.checkMotorizare(@motorizare) = 0 or dbo.checkStoc(@stoc) = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	BEGIN TRY 
		INSERT INTO Masina VALUES ( @id_masina, @model, @motorizare , @id_brand , @stoc);
		SET @return = 1;
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnAddMasina AS INT
EXEC addMasina 12,'BMW 535','3.0',1,14, @returnAddMasina OUTPUT;
PRINT @returnAddMasina;

--procedura de stergere masina
ALTER PROCEDURE deleteMasina
(@id_masina INT,
@return INT OUTPUT)
AS
BEGIN
		DECLARE @ok INT;
		SET @ok = ( SELECT COUNT (id_masina) FROM ClMas WHERE @id_masina=id_masina)
		IF @ok != 0 
		BEGIN
			PRINT 'Nu se poate efectua stergerea'
			RETURN
		END

		DECLARE @before INT;
		SET @before =( SELECT COUNT (id_masina) FROM Masina); 
		DELETE FROM Masina WHERE @id_masina = id_masina
		--DELETE FROM ClMas WHERE id_masina = @id_masina
		DECLARE @after INT;
		SET @after =( SELECT COUNT (id_client) FROM Client);
		IF @after != @before
		BEGIN
			SET @return = 1;
			RETURN
		END
		SET @return = 0;
END;

DECLARE @returnDeleteMasina AS INT
EXEC deleteMasina 12,@returnDeleteMasina OUTPUT;
PRINT @returnDeleteMasina;

--procedura de update masina 
ALTER PROCEDURE updateMasina 
(@id_masina INT,
@model VARCHAR(50),
@motorizare VARCHAR(50),
@id_brand INT,
@stoc INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @returnSelectBrand AS INT
	SET @returnSelectBrand = (SELECT COUNT (*) FROM Brand where id_brand = @id_brand);

	IF dbo.checkModel(@model) = 0 or @returnSelectBrand = 0 or dbo.checkMotorizare(@motorizare) = 0 or dbo.checkStoc(@stoc) = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END

	DECLARE @returnSelectMasina AS INT
	SET @returnSelectMasina = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina);
	IF @returnSelectMasina = 0
	BEGIN 
	SET @return = 0;
		RETURN;
	END

	BEGIN TRY 
		IF @returnSelectBrand  = 1
		BEGIN
		UPDATE Masina
			SET model = @model,
			motorizare = @motorizare,
			id_brand = @id_brand,
			stoc = @stoc
			WHERE
			id_masina = @id_masina
			SET @return = 1;
		END
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnUpdateMasina AS INT
EXEC updateMasina 11,'BMW 535','3.0',2,8, @returnUpdateMasina OUTPUT;
PRINT @returnUpdateMasina;

--procedura de select masina
CREATE PROCEDURE selectMasina
(@id_masina INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @rez INT;
	SET @rez = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina);
	IF @rez = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	SET @return = 1;
	SELECT * FROM Masina where id_masina= @id_masina
END;

DECLARE @returnSelectMasina AS INT
EXEC selectMasina 11, @returnSelectMasina OUTPUT;
PRINT @returnSelectMasina;

--Functie care testeaza modelul unei masini
ALTER FUNCTION checkModel(@nume VARCHAR(30))
RETURNS INT AS
BEGIN
	IF @nume LIKE 'Audi%' or @nume LIKE 'BMW%' or @nume LIKE 'Porsche%'
	BEGIN
		RETURN 1;
	END
	RETURN 0;
	--DECLARE @length INT;
	--SET @length = LEN(@nume);
	--RETURN @length;
END;
CREATE FUNCTION checkMotorizare(@motorizare VARCHAR(30))
RETURNS INT AS
BEGIN
	IF LEN(@motorizare)>0
	BEGIN
		RETURN 1;
	END
	RETURN 0;
	--DECLARE @length INT;
	--SET @length = LEN(@nume);
	--RETURN @length;
END;
CREATE FUNCTION checkStoc(@stoc INT)
RETURNS INT AS
BEGIN
	IF @stoc > 0
	BEGIN
		RETURN 1;
	END
	RETURN 0;
	--DECLARE @length INT;
	--SET @length = LEN(@nume);
	--RETURN @length;
END;
PRINT dbo.checkModel('BMW x1');



------------------------------------
----------4)TABEL MasServ--------------
------------------------------------

--procedura de adaugare MasServ
CREATE PROCEDURE addMasServ 
(@id_masina INT,
@id_servicii INT,
@return INT OUTPUT)
AS
BEGIN

	DECLARE @returnSelectMasina AS INT
	SET @returnSelectMasina = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina);

	DECLARE @returnSelectServicii AS INT
	SET @returnSelectServicii = (SELECT COUNT (*) FROM Servicii where id_servicii= @id_servicii);

	IF @returnSelectMasina = 1 and @returnSelectServicii = 1
	BEGIN
		BEGIN TRY 
			INSERT INTO MasServ VALUES ( @id_masina, @id_servicii);
			SET @return = 1;
			RETURN @return;
		END TRY
		BEGIN CATCH 
			SET @return = 0;
		END CATCH
	END
	SET @return = 0;
	RETURN @return;
END;

DECLARE @returnAddMasServ AS INT
EXEC addMasServ 1,1, @returnAddMasServ OUTPUT;
PRINT @returnAddMasServ;

--procedura de stergere MasServ
CREATE PROCEDURE deleteMasServ 
(@id_masina INT,
@id_servicii INT,
@return INT OUTPUT)
AS
BEGIN
		DECLARE @before INT;
		SET @before =( SELECT COUNT (id_masina) FROM MasServ); 
		DELETE FROM MasServ WHERE @id_masina = id_masina AND @id_servicii = id_servicii
		DECLARE @after INT;
		SET @after =( SELECT COUNT (id_masina) FROM MasServ);
		IF @after != @before
		BEGIN
			SET @return = 1;
			RETURN
		END
		SET @return = 0;
END;

DECLARE @returnDeleteMasServ AS INT
EXEC deleteMasServ 1, 3,@returnDeleteMasServ OUTPUT;
PRINT @returnDeleteMasServ;

--procedura de update MasServ
CREATE PROCEDURE updateMasServ 
(
@id_masina1 INT,
@id_servicii1 INT,
@id_masina2 INT,
@id_servicii2 INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @returnSelectMasina1 AS INT
	SET @returnSelectMasina1 = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina1);

	DECLARE @returnSelectServicii1 AS INT
	SET @returnSelectServicii1 = (SELECT COUNT (*) FROM Servicii where id_servicii= @id_servicii1);

	DECLARE @returnSelectMasina2 AS INT
	SET @returnSelectMasina2 = (SELECT COUNT (*) FROM Masina where id_masina= @id_masina2);

	DECLARE @returnSelectServicii2 AS INT
	SET @returnSelectServicii2 = (SELECT COUNT (*) FROM Servicii where id_servicii= @id_servicii2);

	IF @returnSelectServicii1 = 0 or @returnSelectMasina1 = 0 or @returnSelectServicii2 = 0 or @returnSelectMasina2 = 0
	BEGIN 
		SET @return = 0;
		RETURN @return;
	END
	BEGIN TRY 
		INSERT INTO MasServ VALUES (@id_masina2, @id_servicii2);
		DELETE FROM MasServ WHERE id_masina = @id_masina1 and id_servicii = @id_servicii1
		SET @return = 1;
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnUpdateMasServ AS INT
EXEC updateMasServ 1,1, 1,3, @returnUpdateMasServ OUTPUT;
PRINT @returnUpdateMasServ;

--procedura de select MasServ
ALTER PROCEDURE selectMasServ 
(@id_masina INT,
@id_servicii INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @rez INT;
	SET @rez = (SELECT COUNT (*) FROM MasServ where id_masina= @id_masina and id_servicii = @id_servicii);
	IF @rez = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	SET @return = 1;
	SELECT * FROM MasServ where id_masina = @id_masina and id_servicii = @id_servicii
END;

DECLARE @returnSelectMasServ AS INT
EXEC selectMasServ 1,1, @returnSelectMasServ OUTPUT;
PRINT @returnSelectMasServ;



------------------------------------
----------5)TABEL Brand--------------
------------------------------------

--procedura de adaugare Brand
ALTER PROCEDURE addBrand 
(@id_Brand INT,
@nume VARCHAR(50),
@return INT OUTPUT)
AS
BEGIN
	IF dbo.checkBrand(@nume) = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	BEGIN TRY 
		INSERT INTO Brand VALUES ( @id_brand, @nume);
		SET @return = 1;
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnAddBrand AS INT
EXEC addBrand 7,'porsche', @returnAddBrand OUTPUT;
PRINT @returnAddBrand;

--procedura de stergere Brand
CREATE PROCEDURE deleteBrand 
(@id_brand INT,
@return INT OUTPUT)
AS
BEGIN
		DECLARE @before INT;
		SET @before =( SELECT COUNT (id_brand) FROM Brand); 
		DELETE FROM Brand WHERE @id_brand = id_brand 
		DECLARE @after INT;
		SET @after =( SELECT COUNT (id_brand) FROM Brand);
		IF @after != @before
		BEGIN
			SET @return = 1;
			RETURN
		END
		SET @return = 0;
END;

DECLARE @returnDeleteBrand AS INT
EXEC deleteBrand 7,@returnDeleteBrand OUTPUT;
PRINT @returnDeleteBrand;

--procedura de update Brand
ALTER PROCEDURE updateBrand 
(@id_brand INT,
@nume VARCHAR(50),
@return INT OUTPUT)
AS
BEGIN
	IF dbo.checkBrand(@nume) = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END

	DECLARE @returnSelectBrand AS INT
	SET @returnSelectBrand = (SELECT COUNT (*) FROM Brand where id_brand= @id_brand);
	IF @returnSelectBrand = 0
	BEGIN 
	SET @return = 0;
		RETURN;
	END

	BEGIN TRY 
		UPDATE Brand
			SET nume = @nume WHERE
			id_brand = @id_brand
		SET @return = 1;
	END TRY
	BEGIN CATCH 
		SET @return = 0;
	END CATCH
END;

DECLARE @returnUpdateBrand AS INT
EXEC updateBrand 6,'bmw', @returnUpdateBrand OUTPUT;
PRINT @returnUpdateBrand;

--procedura de select Brand
CREATE PROCEDURE selectBrand 
(@id_brand INT,
@return INT OUTPUT)
AS
BEGIN
	DECLARE @rez INT;
	SET @rez = (SELECT COUNT (*) FROM Brand where id_brand= @id_brand);
	IF @rez = 0
	BEGIN 
		SET @return = 0;
		RETURN;
	END
	SET @return = 1;
	SELECT * FROM Brand where id_brand= @id_brand
END;

DECLARE @returnSelectBrand AS INT
EXEC selectBrand 6, @returnSelectBrand OUTPUT;
PRINT @returnSelectBrand;

--Functie care testeaza numele unui Brand
CREATE FUNCTION checkBrand(@nume VARCHAR(30))
RETURNS INT AS
BEGIN
	IF @nume =  'Audi' or @nume = 'BMW' or @nume = 'Porsche'
	BEGIN
		RETURN 1;
	END
	RETURN 0;
END;
PRINT dbo.checkBrand('audi');


----------------------------------
----------------------------------
----------------------------------
-------------VIEWS----------------
----------------------------------
----------------------------------
----------------------------------

ALTER VIEW viewClient AS
SELECT nume FROM Client

SELECT * FROM viewClient

CREATE INDEX indexClient ON Client (nume ASC);
DROP INDEX indexClient ON Client

SELECT * FROM sys.dm_db_index_usage_stats WHERE database_id = 5 and index_id = 3

-----VIEW 2

ALTER VIEW viewMasina AS
SELECT * FROM Masina

SELECT * FROM viewMasina

CREATE INDEX indexMasina ON Masina (stoc DESC,id_masina ASC, model ASC, motorizare DESC, id_brand ASC)
--CREATE INDEX indexMasina ON Masina (stoc DESC,id_masina ASC, model ASC, motorizare DESC, id_brand ASC)
DROP INDEX indexMasina ON Masina

SELECT * FROM Masina
DELETE FROM Masina

SELECT * FROM sys.dm_db_index_usage_stats WHERE database_id = 5 and index_id = 6

CREATE VIEW viewBrand AS
SELECT nume FROM Brand

SELECT * FROM viewBrand

CREATE INDEX indexBrand ON Brand ( nume ASC)


--------------------------
--------------------------
-------CONSTRAINTS--------
--------------------------
--------------------------

ALTER TABLE Client
ADD CONSTRAINT constraint1 CHECK (LEN(nume) > 0 and LEN(nume)<10)

ALTER TABLE Masina
ADD CONSTRAINT constraint3 CHECK (model LIKE 'Audi%' OR model LIKE 'Bmw%' OR model LIKE 'Porsche%' )
ALTER TABLE Masina
ADD CONSTRAINT constraint4 CHECK (LEN(motorizare)>0 )
ALTER TABLE Masina
ADD CONSTRAINT constraint5 CHECK (stoc>0 )

ALTER TABLE Brand
ADD CONSTRAINT constraint2 CHECK (nume = 'Audi' OR nume = 'Bmw' OR nume = 'Porsche' OR nume = 'Maseratti' OR nume = 'Mercedes')
