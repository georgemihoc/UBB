def creeazaFilm(ident, nume,an,regizor):
    #Functie care creeaza un film pe baza numelui
    #id:ident,nume,an,regizor
    #pre:ident intreg>0, numele string nevid , anul 1850<an<prezent, regizor
    return [ident,nume,an,regizor]

def getIdent(f):
    #Functie care returneaza identificatorul filmului f
    return f[0]

def getAn():
    return f[2]

def getNume(f):

def setNume(f,nume):

def testCreeazaFilm():
    ident = 1
    nume = "the Godfather"
    an = 1972
    regizor = "Copolla"
    f = creeazaFilm(ident,nume,an,regizor)
    assert getIdent(f) == ident
    assert getAn(f)== an
    nume1= "RumbleFish"
    setNume(f,nume1)
    assert getNume(f)== nume1

testCreeazaFilm()