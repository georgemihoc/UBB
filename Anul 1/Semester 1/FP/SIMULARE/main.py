from Console import *
from Repository import *
from Controllers import *
from Validator import ValidOpere
from Test import *
#t = Test()
#t.ruleazaTeste()
repoOpere = OpereFileRepository("date_opere.txt")
#validOpere = ValideazaOpere()
#ctrlOpere = OpereController(repoOpere,validOpere)
ctrlOpere = OpereController(repoOpere)

c= Console(ctrlOpere)
c.run()