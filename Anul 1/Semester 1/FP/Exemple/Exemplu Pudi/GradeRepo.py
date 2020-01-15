from GradeValidator import *

class GradeRepo:
    def __init__(self,filename='Grades.txt'):
        self._data=[]
        self._filename=filename
        self.loadfile()

    def loadfile(self):
        try:
            f=open(self._filename,'r')
            g=f.readline().strip()
            while len(g)>0:
                g=g.split(',')
                try:
                    GradeValidator(Grade(g[0],g[1],g[2],g[3]))
                except Exception as e:
                    print("Mistake in input file")
                self.add(Grade(g[0],g[1],g[2],g[3]))
                g=f.readline().strip()
        except IOError as e:
            print(e)

    def _savefile(self):
        f=open(self._filename,'w')
        try:
            for i in self.getall():
                f.write(i.str()+'\n')
            f.close()
        except IOError as e:
            print(e)

    def add(self,other):
        self._data.append(other)
        self._savefile()

    def getall(self):
        l=[]
        for i in self._data:
            l.append(i)
        return l



