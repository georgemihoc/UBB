from StudentValidator import *

class StudentRepo:
    def __init__(self,filename='Students.txt'):
        self._data=[]
        self._filename=filename
        self.loadfile()

    def loadfile(self):
        try:
            f=open(self._filename,'r')
            s=f.readline().strip()
            while len(s)>0:
                s=s.split(',')
                if len(s)!=3:
                    raise Exception('mistake in text file')
                else:
                    try:
                        StudentValidator(Student(s[0],s[1],s[2]))
                    except Exception as e:
                        raise e
                    self.add(Student(s[0],s[1],s[2]))
                s=f.readline().strip()
        except IOError as e:
            print(e)

    def _savefile(self):
        f=open(self._filename,'w')
        try:
            for i in self.getall():
                f.write(i.__str__()+'\n')
            f.close()
        except IOError as e:
            print(e)



    def add(self,other):
        for i in self._data:
            if i.getID()==other.getID():
                raise ValueError('ID already in list')
        self._data.append(other)
        self._savefile()

    def getall(self):
        l=[]
        for i in self._data:
            l.append(i)
        return l

    def remove(self,id):
        for i in range(0,len(self._data)):
            if self._data[i].getID()==id:
                self._data.pop(i)
                self._savefile()
                return True
        raise ValueError("No student with this ID")


