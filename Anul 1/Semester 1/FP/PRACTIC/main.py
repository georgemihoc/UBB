from console import *
from controllers import *
from repository import *
from validator import *
from Jucator import *
from test import *

#      TESTE
t= Test()
t.ruleaza_teste()

repoJucator = JucatorFileRepository("date.txt","date2.txt")
validJucator = JucatorValidator()
ctrlJucator = JucatorController(repoJucator,validJucator)
cons = Console(ctrlJucator)
cons.run()
