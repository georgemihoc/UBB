from Errors import RepoError
from Person import Person
from Event import Event
from Asign import Asign

class PersonRepository(object):

    def __init__(self,filename):
        self.__elems = []
        self.__filename = filename


    def cauta(self,elem):
        '''
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        '''
        ok = 0

        file = open("date_person.txt","r")
        for line in file:
            if line != '\n':
                person = self.__createPerson(line)
                if int(person.pid) == int(elem.pid):
                    elem2 = person
                    ok = 1
        file.close()
        if ok == 0:
            raise RepoError("Element inexistent!")
        return elem2
        #return self.__elems[pos]

    def __createPerson(self, line):
        if line != '\n':
            fields = line.strip().split(" ")
            st = Person(int(fields[0]), fields[1], fields[2])
            return st

    def adauga(self, elem):
        file = open("date_person.txt","r+")
        ok = 0
        for line in file:
            person = self.__createPerson(line)
            if elem == person:
                ok = 1

        file.close()
        if ok == 0:
            file = open("date_person.txt", "a")
            line = str(elem.get_pid()) + " " + str(elem.get_nume()) + " " + str(elem.get_adresa())
            file.write("\n")
            file.write(line)
            file.close()
        else:
            raise RepoError("Element existent!")
        #self.__elems.append(elem)

        #file = open("date_person.txt","a")
        #file.write(elem.nume)

    def sterge(self, elem):
        '''
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent!")
        del self.__elems[pos]
        '''
        file = open("date_person.txt", "r+")
        file2 = open("date_person2.txt","w")
        ok = 0
        for line in file:
            person = self.__createPerson(line)
            if elem == person:
                ok = 1
            else:
                file2.write(line)

        file.close()
        file2.close()
        if ok == 1:
            file = open("date_person.txt", "w")
            file2 = open("date_person2.txt","r")
            for line in file2:
                file.write(line)
        file.close()
        file2.close()


        file = open("date_asign.txt", "r")
        file2 = open("date_asign2.txt", "w")
        ok = 0
        for line in file:
            if int(line[2]) != int(elem.pid):
                file2.write(line)
            else:
                ok = 1
        file.close()
        file2.close()
        if ok == 1:
            file = open("date_asign.txt", "w")
            file2 = open("date_asign2.txt", "r")
            for line in file2:
                file.write(line)
        file.close()
        file2.close()


    def update(self, elem):
        file = open("date_person.txt", "r+")
        file2 = open("date_person2.txt", "w")
        for line in file:
            person = self.__createPerson(line)
            if elem == person:
                person = elem
            file2.write(person.__str__())
            file2.write('\n')
        file.close()
        file2.close()

        file = open("date_person.txt", "w")
        file2 = open("date_person2.txt", "r")
        for line in file2:
            file.write(line)
        file.close()
        file2.close()
    '''
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent!")
        self.__elems[pos] = elem

    def update_person(self,elem):
        pos = -1
        file = open("date_person.txt","r")
        for line in file:
            if line[1] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent")
        c = 0
        file = open("date_person.txt","r")
        while c<= pos:
    '''


    def __len__(self):
        return len(self.__elems)

    #def getAll(self):
        #return self.__elems[:]


    def getAll(self):

        file = open("date_person.txt","r")
        lista = []
        for line in file:
            person = self.__createPerson(line)
            lista.append(person)
        #return self.__elems[:]
        return lista

class EventRepository(object):

    def __init__(self,filename):
        self.__elems = []
        self.__filename = filename


    def cauta(self, elem):
        ok = -1
        '''
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        '''
        file = open("date_event.txt","r")
        for line in file:
            line = self.__createEvent(line)
            if int(line.id) == int(elem.id):
                elem2 = line
                ok = 1
                break
        file.close()
        if ok == -1:
            raise RepoError("Element inexistent!")
        return elem2
        #return self.__elems[pos]

    def __createEvent(self, line):
        fields = line.strip().split(" ")
        st = Event(int(fields[0]), fields[1], fields[2], fields[3])
        return st

    def adauga(self, elem):
        file = open("date_event.txt","r+")
        ok = 0
        for line in file:
            person = self.__createEvent(line)
            if elem == person:
                ok = 1

        file.close()
        if ok == 0:
            file = open("date_event.txt", "a")
            line = str(elem.get_id()) + " " + str(elem.get_data()) + " " + str(elem.get_data()) + " " + str(elem.get_desc())
            file.write("\n")
            file.write(line)
            file.close()
        else:
            raise RepoError("Element existent!")
        #self.__elems.append(elem)

        #file = open("date_person.txt","a")
        #file.write(elem.nume)

    def sterge(self, elem):
        '''
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent!")
        del self.__elems[pos]
        '''
        file = open("date_event.txt", "r+")
        file2 = open("date_event2.txt","w")
        ok = 0
        for line in file:
            event = self.__createEvent(line)
            if elem == event:
                ok = 1
            else:
                file2.write(line)

        file.close()
        file2.close()
        if ok == 1:
            file = open("date_event.txt", "w")
            file2 = open("date_event2.txt","r")
            for line in file2:
                file.write(line)
        file.close()
        file2.close()

        file = open("date_asign.txt","r")
        file2 = open("date_asign2.txt","w")
        ok = 0
        for line in file:
            if int(line[2]) != int(elem.id):
                file2.write(line)
            else:
                ok = 1
        file.close()
        file2.close()
        if ok == 1:
            file = open("date_asign.txt", "w")
            file2 = open("date_asign2.txt","r")
            for line in file2:
                file.write(line)
        file.close()
        file2.close()



    def update(self, elem):
        file = open("date_event.txt", "r+")
        file2 = open("date_event2.txt", "w")
        for line in file:
            event = self.__createEvent(line)
            if elem == event:
                event = elem
            file2.write(event.__str__())
            file2.write('\n')
        file.close()
        file2.close()

        file = open("date_event.txt", "w")
        file2 = open("date_event2.txt", "r")
        for line in file2:
            file.write(line)
        file.close()
        file2.close()
    '''
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent!")
        self.__elems[pos] = elem

    def update_person(self,elem):
        pos = -1
        file = open("date_person.txt","r")
        for line in file:
            if line[1] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent")
        c = 0
        file = open("date_person.txt","r")
        while c<= pos:
    '''


    def __len__(self):
        return len(self.__elems)

    #def getAll(self):
        #return self.__elems[:]


    def getAll(self):

        file = open("date_event.txt","r")
        lista = []
        for line in file:
            event = self.__createEvent(line)
            lista.append(event)
        #return self.__elems[:]
        return lista

class AsignRepository(object):

    def __init__(self,filename):
        self.__elems = []
        self.__filename = filename


    def cauta(self, elem):
        ok = -1
        '''
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        '''
        file = open("date_asign.txt","r")
        for line in file:
            asign = self.__createAsign(line)
            if asign == elem:
                elem2 = elem
                ok = 1
                break
        file.close()
        if ok == -1:
            raise RepoError("Element inexistent!")
        return elem2

        #return self.__elems[pos]

    def __createAsign(self, line):
        fields = line.strip().split(" ")
        st = Asign(int(fields[0]), int(fields[1]))
        return st

    def adauga(self, elem):
        file = open("date_asign.txt","r+")
        ok = 0
        for line in file:
            asign = self.__createAsign(line)
            if elem == asign:
                ok = 1

        file.close()
        if ok == 0:
            file = open("date_asign.txt", "a")
            line = str(elem.get_pid()) + " " + str(elem.get_eid())
            file.write("\n")
            file.write(line)
            file.close()
        else:
            raise RepoError("Element existent!")
        #self.__elems.append(elem)
        #file = open("date_person.txt","a")
        #file.write(elem.nume)

    def sterge(self, elem):
        '''
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent!")
        del self.__elems[pos]
        '''
        file = open("date_asign.txt", "r+")
        file2 = open("date_asign2.txt","w")
        ok = 0
        for line in file:
            person = self.__createAsign(line)
            if elem == person:
                ok = 1
            else:
                file2.write(line)

        file.close()
        file2.close()
        if ok == 1:
            file = open("date_asign.txt", "w")
            file2 = open("date_asign2.txt","r")
            for line in file2:
                file.write(line)
        file.close()
        file2.close()


    def update(self, elem):
        file = open("date_asign.txt", "r+")
        file2 = open("date_asign2.txt", "w")
        for line in file:
            asign = self.__createAsign(line)
            if elem == asign:
                asign = elem
            file2.write(asign.__str__())
        file.close()
        file2.close()

        file = open("date_asign.txt", "w")
        file2 = open("date_asign2.txt", "r")
        for line in file2:
            file.write(line)
        file.close()
        file2.close()
    '''
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent!")
        self.__elems[pos] = elem

    def update_person(self,elem):
        pos = -1
        file = open("date_person.txt","r")
        for line in file:
            if line[1] == elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("Element inexistent")
        c = 0
        file = open("date_person.txt","r")
        while c<= pos:
    '''


    def __len__(self):
        return len(self.__elems)

    #def getAll(self):
        #return self.__elems[:]


    def getAll(self):

        file = open("date_asign.txt","r")
        lista = []
        for line in file:
            asign = self.__createAsign(line)
            lista.append(asign)
        #return self.__elems[:]
        return lista



class PersonFileRepository(PersonRepository):

    def __init__(self, filename):
        self.__filename = filename
        PersonRepository.__init__(self,self.__filename)
        #self.__loadFromFile()

    def __createPerson(self, line):
        fields = line.split(" ")
        st = Person(int(fields[0]), fields[1], fields[2])
        return st

    def __loadFromFile(self):
        f = open(self.__filename)
        for line in f:
            if line.strip() == "":
                continue
            p = self.__createPerson(line)
            Repository.adauga(self, p)
        f.close()

    def adaugare(self, p):
        PersonRepository.adauga(self, p)
        '''
        f = open(self.__filename, "a")
        line = str(p.get_pid()) + " " + str(p.get_nume()) + " " + str(p.get_adresa())
        f.write("\n")
        f.write(line)
        
        f.close()
        '''

    def __writeToFile(self):
        person = PersonRepository.getAll(self)
        f = open(self.__filename, "w")
        for p in person:
            line = str(p.get_pid()) + " " + str(p.get_nume()) + " " + str(p.get_adresa())
            f.write(line)
            f.write("\n")
        f.close()

    def sterge(self, p):
        PersonRepository.sterge(self, p)
        #self.__writeToFile()

    def update(self, p):
        PersonRepository.update(self, p)
        #self.__writeToFile()

class EventFileRepository(EventRepository):

    def __init__(self, filename):
        self.__filename = filename
        EventRepository.__init__(self,self.__filename)
        #self.__loadFromFile()

    def __createEvent(self, line):
        fields = line.split(" ")
        st = Event(int(fields[0]), fields[1], fields[2], fields[3])
        return st

    def __loadFromFile(self):
        f = open(self.__filename)
        for line in f:
            if line.strip() == "":
                continue
            e = self.__createEvent(line)
            EventRepository.adauga(self, e)
        f.close()

    def adaugare(self, e):
        EventRepository.adauga(self, e)
        '''
        f = open(self.__filename, "a")
        line = str(e.get_id()) + " " + str(e.get_data()) + " " + str(e.get_timp()) + " " + str(e.get_desc())
        f.write("\n")
        f.write(line)
        f.close()
        '''

    def __writeToFile(self):
        event = EventRepository.getAll(self)
        f = open(self.__filename, "w")
        for e in event:
            line = str(e.get_id()) + " " + str(e.get_data()) + " " + str(e.get_timp()) + " " + str(e.get_desc())
            f.write(line)
            f.write("\n")
        f.close()

    def sterge(self, e):
        EventRepository.sterge(self, e)
        #self.__writeToFile()

    def update(self, e):
        EventRepository.update(self, e)
        #self.__writeToFile()

class AsignFileRepository(AsignRepository):

    def __init__(self, filename):
        self.__filename = filename
        AsignRepository.__init__(self,self.__filename)
        #self.__loadFromFile()

    def __createAsign(self, line):
        fields = line.split(" ")
        st = Asign(int(fields[0]), int(fields[1]))
        return st

    def __loadFromFile(self):
        f = open(self.__filename)
        for line in f:
            if line.strip() == "":
                continue
            a = self.__createAsign(line)
            Repository.adauga(self, a)
        f.close()

    def adaugare(self, a):
        AsignRepository.adauga(self, a)
        '''
        f = open("date_asign", "a")
        line = str(a.get_pid()) + " " + str(a.get_eid())
        f.write("\n")
        f.write(line)
        f.close()
        '''

    def __writeToFile(self):
        asign = AsignRepository.getAll(self)
        f = open(self.__filename, "w")
        for a in asign:
            line = str(a.get_pid()) + " " + str(a.get_eid())
            f.write(line)
            f.write("\n")
        f.close()

    def sterge(self, a):
        AsignRepository.sterge(self, a)
        #self.__writeToFile()

    def update(self, a):
        AsignRepository.update(self, a)
        #self.__writeToFile()