--1)Query care ia din tabela Angajat numele tuturor angajatiilor a caror pozitie incepe cu M
SELECT nume AS [Nume Angajat],pozitie AS [Pozitie], salar AS [Salar] 
FROM Angajat 
WHERE pozitie LIKE 'M%';

-- 2)Query care arata toate MODELELE de masini disponibile pt inchiriere si pretul pt acestea
SELECT M.model AS Model, S.denumire AS [Tip Serviciu],S.pret AS [Pret] 
FROM Masina M INNER JOIN MasServ X ON M.id_masina = X.id_masina 
INNER JOIN Servicii S ON X.id_servicii=S.id_servicii 
WHERE S.denumire='inchiriere';

--3)Query care arata cate masini are asociat fiecare client
SELECT C.nume AS [Nume Client] , COUNT(C.id_client) AS [numar masini]
FROM Client C INNER JOIN ClMas X ON C.id_client=X.id_client 
GROUP BY C.id_client,C.nume HAVING COUNT(id_masina)>0;

--4)Query care arata toti angajatii care se ocupa de vanzari sau de inchirieri
SELECT DISTINCT A.nume AS [Nume angajat], S.denumire AS [Tipul serviciului]
FROM Angajat A INNER JOIN ServAng X ON A.id_angajat = X.id_angajat 
INNER JOIN Servicii S ON X.id_servicii=S.id_servicii 
WHERE S.denumire='inchiriere' OR S.denumire='cumparare';

--5)Query care arata toate capacitatile cilindrice a masinilor ( distincte)
SELECT DISTINCT  M.motorizare AS [motorizari disponibile]
FROM Masina M INNER JOIN Brand B ON M.id_brand=B.id_brand

--6)Query care arata fiecare client la ce filiala poate merge in functie de serviciul dorit+ angajatul posibil.
SELECT  DISTINCT C.nume AS [Nume Client], F.locatie AS [Filiala posibila], A.nume AS [Nume angajat]
FROM Client C INNER JOIN ClMas X1 ON C.id_client= X1.id_client
INNER JOIN Masina M ON X1.id_masina=M.id_masina
INNER JOIN MasServ X2 ON M.id_masina=X2.id_masina
INNER JOIN Servicii S ON X2.id_servicii=S.id_servicii
INNER JOIN ServAng X3 ON S.id_servicii=X3.id_servicii
INNER JOIN Angajat A ON X3.id_angajat=A.id_angajat
INNER JOIN Filiala F ON A.id_filiala=F.id_filiala

--7)Query care arata stocul total de masini pentru fiecare serviciu
SELECT S.denumire AS [Nume serviciu] , SUM(M.stoc) AS [Stocul total]
FROM Servicii S INNER JOIN MasServ X ON S.id_servicii=X.id_servicii 
INNER JOIN Masina M ON X.id_masina = M.id_masina
GROUP BY S.id_servicii,S.denumire HAVING COUNT(M.id_masina)>0

--8) Query care arata cate servicii are disponibila fiecare filiala
SELECT F.locatie AS [Filiala] , COUNT(A.id_filiala) AS [Numar servicii disponibile]
FROM Servicii S INNER JOIN ServAng X ON S.id_servicii=X.id_servicii 
INNER JOIN Angajat A ON X.id_angajat = A.id_angajat
INNER JOIN Filiala F ON A.id_filiala = F.id_filiala
GROUP BY F.id_filiala,F.locatie HAVING COUNT(A.id_angajat)>0;

--9)Query care arata ce branduri sunt disponibile pt test-drive
SELECT 
    Servicii.denumire AS Serviciu , Brand.nume AS Brand
FROM
    Servicii, Brand,MasServ, Masina
WHERE
	Servicii.denumire='test-drive'
	AND
	Servicii.id_servicii= MasServ.id_servicii
	AND
	MasServ.id_masina = Masina.id_masina
	AND
	Masina.id_brand= Brand.id_brand

--10) Query care arata motorizarile preferate fiecarui client
SELECT DISTINCT Client.nume AS [Nume client], Masina.motorizare AS [Motorizare preferata]
FROM Masina,Client,ClMas
WHERE motorizare>='2.0'
	AND 
	Client.id_client= ClMas.id_client
	AND
	ClMas.id_masina=Masina.id_masina