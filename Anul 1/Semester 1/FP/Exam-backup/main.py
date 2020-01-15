from console import *
from controllers import *
from repository import *
from validator import *
from test import *
t= Test()
t.ruleaza_teste()

repoProdus = ProdusFileRepository("date.txt","date2.txt")
validProdus = ProdusValidator()
ctrlProdus = ProdusController(repoProdus,validProdus)
cons = Console(ctrlProdus)
cons.run()
