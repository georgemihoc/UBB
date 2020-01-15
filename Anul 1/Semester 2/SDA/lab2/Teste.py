from Colectie import Colectie, IteratorColectie

def testAll():
    c = Colectie()
    assert (c.dim() == 0)
    assert (c.vida())

    c.adauga(4)
    c.adauga(11)
    c.adauga(4)
    c.adauga(77)
    c.adauga(8)

    assert (c.dim() == 5)
    assert (c.vida() == False)

    assert (c.sterge(44) == False)
    assert (c.sterge(11) == True)
    assert (c.dim() == 4)
    assert (c.nrAparitii(4) == 2)
    assert (c.cauta(77))
    assert (c.cauta(13) == False)

    itc = c.iterator()
    assert (itc.valid())
    cont = 0
    while (itc.valid()):
        cont += 1
        e = itc.element()
        itc.urmator()
        assert (c.cauta(e))
    assert (cont == c.dim())
    itc.prim()
    assert (itc.valid())


#testAll()