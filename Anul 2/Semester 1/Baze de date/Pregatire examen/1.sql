CREATE DATABASE CFR
GO

CREATE TABLE Tipuri_de_Tren
(
	cod_tt INT PRIMARY KEY IDENTITY,
	descriere VARCHAR(30)
);

CREATE TABLE Trenuri 
(
	cod_t INT PRIMARY KEY IDENTITY,
	nume VARCHAR(30),
	cod_tt INT FOREIGN KEY REFERENCES Tipuri_de_Tren(cod_tt)
);

CREATE TABLE Statii 
(
	cod_s INT PRIMARY KEY IDENTITY,
	nume VARCHAR(30)	
);

CREATE TABLE Rute
(
	cod_r INT PRIMARY KEY IDENTITY,
	nume VARCHAR(30),
	cod_t INT FOREIGN KEY REFERENCES Trenuri(cod_t)
);

CREATE TABLE RuteStatii
(
	cod_r INT FOREIGN KEY REFERENCES Rute(cod_r),
	cod_s INT FOREIGN KEY REFERENCES Statii(cod_s),
	oraS TIME,
	oraP TIME
	CONSTRAINT pk_RuteStatii PRIMARY KEY(cod_r, cod_s)
);

CREATE PROCEDURE addStatie( @ruta INT , @statie INT , @oraS TIME , @oraP TIME)
AS 
BEGIN 
	DECLARE @Rez INT;
	DECLARE @Rez1 INT;
	SET @Rez = ( SELECT COUNT (*) FROM RuteStatii WHERE @ruta=cod_r AND @statie = statie);

	IF @Rez = 1
		UPDATE RuteStatii SET oraS = @oraS AND oraP = @oraP WHERE  @ruta=cod_r AND @statie = statie);
	ELSE
	BEGIN
		SET @Rez = ( SELECT COUNT (*) FROM Rute WHERE @ruta=cod_r);
		SET @Rez1 = ( SELECT COUNT (*) FROM Statii WHERE @statie=cod_s);
		IF @Rez = 1 AND @Rez1 = 1
			INSERT INTO RuteStatii VALUES (@cod_r, @cod_s, @oraS, @oraP)
	END
END

EXEC addStatie(2,3,10:00, 10:26)


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










