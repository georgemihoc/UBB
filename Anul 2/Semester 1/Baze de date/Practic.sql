CREATE DATABASE Restaurante
GO
USE Restaurante

CREATE TABLE Tipuri_de_restaurante
(
	cod_tr INT PRIMARY KEY IDENTITY,
	nume VARCHAR(30),
	descriere VARCHAR(30)
);

CREATE TABLE Orase
(
	cod_o INT PRIMARY KEY IDENTITY,
	nume VARCHAR(30)
);
CREATE TABLE Restaurante
(
	cod_r INT PRIMARY KEY IDENTITY,
	nume VARCHAR(30),
	adresa VARCHAR(30),
	tel VARCHAR(30),
	cod_o INT FOREIGN KEY REFERENCES Orase(cod_o),
	cod_tr INT FOREIGN KEY REFERENCES Tipuri_de_restaurante(cod_tr)
);

CREATE TABLE Utilizatori
(
	cod_u INT PRIMARY KEY IDENTITY,
	nume VARCHAR(30),
	email VARCHAR(30),
	parola VARCHAR(30)
);

CREATE TABLE Note
(
	cod_u INT FOREIGN KEY REFERENCES Utilizatori(cod_u),
	cod_r INT FOREIGN KEY REFERENCES Restaurante(cod_r),
	nota REAL,
	CONSTRAINT pk_Note PRIMARY KEY(cod_u, cod_r)
);




ALTER PROCEDURE addNota (@restaurant INT , @utilizator INT , @nota REAL)
AS 
BEGIN 
	IF( EXISTS(SELECT * FROM Note WHERE @restaurant = cod_r AND @utilizator = cod_u))
	BEGIN
		UPDATE Note SET nota = @nota WHERE  @restaurant = cod_r AND @utilizator = cod_u;
	END
	ELSE
	BEGIN
		IF(EXISTS(SELECT * FROM Restaurante WHERE @restaurant = cod_r) AND EXISTS(SELECT * FROM Utilizatori WHERE @utilizator = cod_u))
			INSERT INTO Note VALUES(@utilizator,@restaurant,@nota);
	END
END

EXEC addNota 6,1,10;
SELECT * FROM Note

ALTER VIEW RestauranteBune AS
	SELECT R.nume AS Nume, AVG(N.nota) AS Media FROM Restaurante AS R 
	INNER JOIN Note AS N ON 
	R.cod_r = N.cod_r GROUP BY R.cod_r,R.nume HAVING AVG(N.nota)>5;
GO

EXEC addNota 6,2,0;
EXEC addNota 7,1,5;
EXEC addNota 7,2,6;
EXEC addNota 6,3,9;
SELECT * FROM RestauranteBune;
GO