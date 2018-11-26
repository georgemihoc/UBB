from teste.Test import Test
from repo.Repository import Repository
from business.Controllers import ElevController,ProblemaController,AsignController
from ui.Console import Console
from validare.Validator import ElevValidator,ProblemaValidator,AsignValidator
t = Test()
t.ruleazaTeste()
repoElev = Repository()
repoProblema = Repository()
repoAsign = Repository()
validElev = ElevValidator()
validProblema = ProblemaValidator()
validAsign = AsignValidator()
ctrlElev = ElevController(repoElev,validElev)
ctrlProblema = ProblemaController(repoProblema,validProblema)
ctrlAsign = AsignController(repoElev,repoProblema,repoAsign,validAsign)
cons = Console(ctrlElev,ctrlProblema,ctrlAsign)
cons.run()