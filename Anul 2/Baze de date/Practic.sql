--construire database
CREATE DATABASE CFR;
GO

USE CFR;

--1)creare tabele
CREATE TABLE Tipuri_de_tren (
	cod_tt INT PRIMARY KEY IDENTITY,
	desc VARCHAR(100));

CREATE TABLE Trenuri (
	cod_t INT PRIMARY KEY IDENTITY,
	nume VARCHAR(50),
	cod_tt INT FOREIGN KEY REFERENCES Tipuri_de_tren(cod_tt));

CREATE TABLE Rute (
	cod_r INT PRIMARY KEY IDENTITY,
	nume VARCHAR(50),
	cod_t INT FOREIGN KEY REFERENCES Trenuri(cod_t));

CREATE TABLE Statii (
	cod_s INT PRIMARY KEY IDENTITY,
	nume VARCHAR(100));

CREATE TABLE RuteStatii (
	cod_r INT FOREIGN KEY REFERENCES Rute(cod_r),
	cod_s INT FOREIGN KEY REFERENCES Statii(cod_s),
	oraS TIME,
	oraP TIME,
	CONSTRAINT pk_RuteStatii PRIMARY KEY (cod_r,cod_s);
);
GO

--2)procedura care adauga o noua statie rutei ( varianta cu EXISTS pt verificarea existentei)
CREATE PROCEDURE adaugaStatie ( @ruta INT , @statie INT, @oraS TIME, @oraP TIME) 
AS 
BEGIN
	IF (EXISTS (SELECT * FROM RuteStatii WHERE cod_s = @statie AND cod_r = @ruta))
	BEGIN
		UPDATE RuteStatii SET oraS = @oraS , oraP = @oraP
		WHERE cod_s = @statie AND cod_r = @ruta;
	END
	ELSE INSERT INTO RuteStatii (cod_s, cod_r, oraS, oraP) VALUES (@cod_s,@cod_r,@oraS,@oraP);
END
GO
EXEC adaugaStatie 1, 1, '2:30:00', '2:45:00';

--2)procedura care adauga o noua statie rutei ( varianta cu COUNT pt verificarea existentei)
CREATE PROCEDURE adaugaStatie1(@ruta INT , @statie INT , @oraS TIME , @oraP TIME)
AS
BEGIN 
	DECLARE @nr INT;
	SELECT @nr  = COUNT (*) FROM RuteStatii WHERE cod_s = @statie AND cod_r = @ruta; 
	IF @nr = 0 
	BEGIN
		INSERT INTO RuteStatii(cod_r, cod_s, oraS, oraP) VALUES (@ruta, @statie, @oraS, @oraP);
	END
	ELSE UPDATE RuteStatii SET oraS = @oraS , oraP = @oraP 
		WHERE cod_s = @statie AND cod_r = @ruta;
END
GO

--3)creare view cu numele rutelor care contin toate statiile
CREATE VIEW RuteComplete AS
	SELECT R.nume FROM Rute AS R 
	INNER JOIN RuteStatii AS Rs ON 
	R.cod_r = Rs.cod_r GROUP BY R.cod_r, R.nume HAVING COUNT (*) = (SELECT COUNT (*) FROM Statii);
GO

SELECT * FROM RuteComplete;
GO


--3') creare functie care afiseaza toate statiile care au mai mult de un tren la un anumint moment din zi
CREATE FUNCTION ufStatieNrTrenuri()
RETURNS TABLE AS
RETURN SELECT S.nume AS statie FROM Statii S INNER JOIN RuteStatii Rs
ON S.cod_s = Rs.cod_s INNER JOIN RuteStatii Rs2 
ON Rs.cod_s = Rs2.cod_s AND Rs.cod_r<>Rs2.cod_r
WHERE (Rs.oraS BETWEEN Rs2.oraS AND Rs2.oraP) OR (Rs.oraP BETWEEEN Rs2.oraS AND Rs2.oraP);
GO;
SELECT * FROM ufStatieNrTrenuri();
























