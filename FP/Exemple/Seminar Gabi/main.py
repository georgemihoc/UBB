from teste.Test import Test
from repo.Repository import Repository
from business.Controllers import AsignController,SaliController,ProfiController
from ui.Console import Console
from validare.Validator import SalaValidator
t = Test()
t.ruleazaTeste()
repoSali = Repository()
repoProfi = Repository()
repoAsign = Repository()
validSala = SalaValidator()
ctrlSali = SaliController(repoSali,validSala)
ctrlProfi = ProfiController(repoProfi)
ctrlAsign = AsignController(repoSali,repoProfi,repoAsign)
cons = Console(ctrlSali,ctrlProfi,ctrlAsign)
cons.run()