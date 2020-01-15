from errors.Errors import ValidError, RepoError

class Console(object):
    
    
    def __init__(self, ctrlElev, ctrlProblema, ctrlAsign):
        self.ctrlElev = ctrlElev
        self.ctrlProblema = ctrlProblema
        self.ctrlAsign = ctrlAsign
    
    def __uiAddElev(self,params):
        if len(params)!=3:
            print("nr params invalid!")
            return
        ident = int(params[0])
        nume = params[1]
        grup = int(params[2])
        self.ctrlElev.adaugaElev(ident,nume,grup)
    
    def __uiPrintElev(self,params):
        if len(params)>0:
            print("nr params invalid!")
            return 
        print("Elevii sunt:")
        elev = self.ctrlElev.getAllElev()
        if len(elev)>0:
            for e in elev:
                print(e)
        else:
            print("Lista goala!")
    
    def __uiDeleteElev(self,params):
        if len(params)!=1:
            print("nr params invalid!")
            return
        ident = int(params[0])
        nume = "Nume"
        grup = 1
        self.ctrlElev.stergeElev(ident,nume,grup)
        
    def __uiUpdateElev(self,params):
        if len(params)!=3:
            print("nr params invalid!")
            return 
        ident = int(params[0])
        nume = params[1]
        grup = int(params[2])
        self.ctrlElev.modificaElev(ident,nume,grup)
    
    def __uiAddProblema(self,params):
        if len(params)!=3:
            print("nr params invalid!")
            return
        lab = int(params[0])
        desc = params[1]
        dl = int(params[2])
        self.ctrlProblema.adaugaProblema(lab,desc,dl)
    
    def __uiPrintProblema(self,params):
        if len(params)>0:
            print("nr params invalid!")
            return 
        print("Problemele sunt:")
        prob = self.ctrlProblema.getAllProblema()
        if len(prob)>0:
            for p in prob:
                print(p)
        else:
            print("Lista goala!")
    
    def __uiDeleteProblema(self,params):
        if len(params)!=1:
            print("nr params invalid!")
            return
        lab = int(params[0])
        desc = "Nume"
        dl = 1
        self.ctrlProblema.stergeProblema(lab,desc,dl)
    
    def __uiUpdateProblema(self,params):
        if len(params)!=3:
            print("nr params invalid!")
            return 
        lab = int(params[0])
        desc = params[1]
        dl = int(params[2])
        self.ctrlProblema.modificaProblema(lab,desc,dl)
    
    def __uiAddNota(self,params):
        if len(params)!=3:
            print("nr params invalid!")
            return 
        eid = int(params[0])
        lab = int(params[1])
        nota = int(params[2])
        self.ctrlAsign.adaugaNota(eid,lab,nota)
    
    def __uiPrintNote(self,params):
        if len(params)>0:
            print("nr params invalid!")
            return 
        print("Notele sunt:")
        a = self.ctrlAsign.getAllAsign()
        if len(a)>0:
            for p in a:
                print(p)
        else:
            print("Lista goala!")
    
    def __uiRandomElev(self,params):
        if len(params)!=1:
            print("nr params invalid!")
            return
        self.ctrlElev.randomElev(int(params[0]))
    
    def __uiRandomProblema(self,params):
        if len(params)!=1:
            print("nr params invalid!")
            return
        self.ctrlProblema.randomProblema(int(params[0])) 

    
    def run(self):
        print("1.Adaugare elev - addelev")
        print("2.Printare elev - printelev")
        print("3.Adaugare problema - addprob")
        print("4.Printare problema - printprob")
        print("5.Stergere elev - delelev")
        print("6.Stergere problema - delprob")
        print("7.Modificare elev - modelev")
        print("8.Modificare problema - modprob")
        print("9.Adaugare nota - addnota")
        print("10.Afiseaza note - printnote")
        print("11.Elevi random - randomelev")
        print("12.Problema random - randomprob")
        comenzi ={"addelev":self.__uiAddElev,"printelev":self.__uiPrintElev,"addprob":self.__uiAddProblema,"printprob":self.__uiPrintProblema,"delelev":self.__uiDeleteElev,"delprob":self.__uiDeleteProblema,"modelev":self.__uiUpdateElev,"modprob":self.__uiUpdateProblema,"addnota":self.__uiAddNota,"printnote":self.__uiPrintNote,"randomelev":self.__uiRandomElev,"randomprob":self.__uiRandomProblema}
        while True:
            cmd = input(">>")
            params = cmd.split(" ")
            if cmd == "exit":
                return
            elif params[0] in comenzi:
                try:
                    comenzi[params[0]](params[1:])
                except ValueError:
                    print("tip de data invalid!")
                except ValidError as ve:
                    print("Validation exc:")
                    print(ve)
                except RepoError as re:
                    print("Repo exc:")
                    print(re)
                
            else:
                print("comanda invalida!")