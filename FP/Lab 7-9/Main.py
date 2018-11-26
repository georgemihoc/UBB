from Test import Test
from Repository import Repository
from Controllers import PersonController,EventController,AsignController
from Console import Console
from Validator import PersonValidator,EventValidator,AsignValidator
t = Test()
t.ruleaza_Teste()
repoPerson = Repository()
repoEvent = Repository()
repoAsign = Repository()
validPerson = PersonValidator()
validEvent = EventValidator()
validAsign = AsignValidator()
ctrlPerson = PersonController(repoPerson,validPerson)
ctrlEvent = EventController(repoEvent,validEvent)
ctrlAsign = AsignController(repoPerson,repoEvent,repoAsign,validAsign)
cons = Console(ctrlPerson,ctrlEvent,ctrlAsign)
cons.run()