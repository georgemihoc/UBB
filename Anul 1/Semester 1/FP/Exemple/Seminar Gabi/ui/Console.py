from errors.Errors import ValidError, RepoError
class Console(object):
    
    
    def __init__(self, ctrlSali, ctrlProfi, ctrlAsign):
        self.ctrlSali = ctrlSali
        self.ctrlProfi = ctrlProfi
        self.ctrlAsign = ctrlAsign

    
    def __uiAddSala(self,params):
        if len(params)!=3:
            print("nr params invalid!")
            return
        ident = int(params[0])
        nume = params[1]
        capac = int(params[2])
        self.ctrlSali.adaugaSala(ident,nume,capac)
    
    def __uiPrintSali(self,params):
        if len(params)>0:
            print("nr params invalid!")
            return 
        print("Salile curente sunt:")
        sali = self.ctrlSali.getAllSali()
        if len(sali)>0:
            for sala in sali:
                print(sala)
        print("Lista goala!")
    
    
    def run(self):
        comenzi ={"addsala":self.__uiAddSala,"printsali":self.__uiPrintSali}
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
    
    
    



