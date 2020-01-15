from StudentRepo import *
from GradeRepo import *
from random import randint

class Controller:
    def __init__(self,Studentsrepo,Graderepo):
        self._Srepo=Studentsrepo
        self._Grepo=Graderepo

    def addS(self,student):
        try:
            StudentValidator(student)
        except Exception as e:
            print(e)
        self._Srepo.add(student)

    def addG(self,grade):
        try:
            GradeValidator(grade)
        except Exception as e:
            print(e)
        self._Grepo.add(grade)

    def removeS(self,id):
        for i in self._Grepo.getall():
            if i.getID()==id:
                raise Exception("Student already has a grade, so he cant be removed")
        self._Srepo.remove(id)

    def assignProblem(self,id,lab,problem):
        for i in self._Grepo.getall():
            if i.getID()==id and i.getLab()==lab:
                raise Exception("Student already has a problem at this lab")
        self._Grepo.add(Grade(id,lab,problem,0))

    def assignLab(self,lab,group):
        for i in self._Srepo.getall():
            if i.getGroup()==group:
                try:
                    self.assignProblem(i.getID(),lab,randint(1,20))
                except Exception as e:
                    print("Student "+i.getID()+" already has a problem assigned")

    def GradeS(self,id,lab,grade):
        for i in self._Grepo.getall():
            if i.getID()==id and i.getLab()==lab and i.getGrade()==0:
                if grade<1 or grade>10:
                    raise Exception('invalid grade')
                else:
                    i.setGrade(grade)
                    self._Grepo._savefile()
                    return True
        raise Exception('student already has a grade')

    def DisplayS(self):
        return self._Srepo.getall()

    def DisplayG(self):
        return self._Grepo.getall()

    def AverageGrade(self,id):
        s=0
        c=0
        for i in self._Grepo.getall():
            if i.getID()==id:
                s=s+i.getGrade()
                c+=1
        if c>0:
            return s/c
        return 0

    def AverageGroup(self,group):
        def Take(elem):
            return elem._grade
        l=[]
        for i in self._Srepo.getall():
            if i.getGroup()==group:
                l.append(StudentGroup(i.getID(),group,self.AverageGrade(i.getID())))
        l.sort(key=Take)
        l.reverse()
        return l

class StudentGroup:
    def __init__(self,id,group,grade):
        self._id=id
        self._group=group
        self._grade=grade

    def get(self):
        return self._grade

    def __str__(self):
        return "stud id:"+str(self._id)+" group:"+str(self._group)+' grade:'+str(self._grade)
