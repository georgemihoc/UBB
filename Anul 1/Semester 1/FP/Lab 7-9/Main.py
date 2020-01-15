from Test import Test
from Repository import *
from Controllers import PersonController,EventController,AsignController
from Console import Console
from Validator import PersonValidator,EventValidator,AsignValidator
t = Test()
t.ruleazaTeste()
#repoPerson = Repository()
repoPerson = PersonFileRepository("date_person.txt")
#repoEvent = Repository()
repoEvent = EventFileRepository("date_event.txt")
#repoAsign = Repository()
repoAsign = AsignFileRepository("date_asign.txt")
validPerson = PersonValidator()
validEvent = EventValidator()
validAsign = AsignValidator()
ctrlPerson = PersonController(repoPerson,validPerson)
ctrlEvent = EventController(repoEvent,validEvent)
ctrlAsign = AsignController(repoPerson,repoEvent,repoAsign,validAsign)
cons = Console(ctrlPerson,ctrlEvent,ctrlAsign)
cons.run()