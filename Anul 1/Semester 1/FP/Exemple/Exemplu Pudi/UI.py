from Controller import *

class UI:
    def __init__(self,controller):
        self._controller=controller

    def PrintMenu(self):
        s="\n Command Menu: \n"
        s+="1.Add Student \n"
        s+="2.Remove Student \n"
        s+="3.Assign problem to a Student \n"
        s+="4.Assign lab to a group \n"
        s+="5.Grade a student \n"
        return s

    def loop(self):
        while True:
            try:
                print(self.PrintMenu())
                inp=int(input("Give command #:"))
                if inp==1:
                    id=int(input("Give student id:"))
                    name=(input("Give student name:"))
                    group=int(input("Give student group:"))
                    self._controller.addS(Student(id,name,group))
                elif inp==2:
                    id=int(input("Give id to be removed:"))
                    self._controller.removeS(id)
                elif inp==3:
                    id = int(input("Give student id:"))
                    lab = int(input("Give lab#:"))
                    problem = int(input("Give problem#:"))
                    self._controller.assignProblem(id,lab,problem)
                elif inp==4:
                    group=int(input("Give Group#:"))
                    lab=int(input("Give lab#:"))
                    self._controller.assignLab(lab,group)
                elif inp==5:
                    id = int(input("Give student id:"))
                    lab = int(input("Give lab#:"))
                    grade = int(input("Give grade:"))
                    self._controller.GradeS(id,lab,grade)
                elif inp==6:
                    for i in (self._controller.DisplayS()):
                        print(i.__str__())
                elif inp == 7:
                    for i in (self._controller.DisplayG()):
                        print(i.__str__())
                elif inp == 8:
                    group=int(input('give group'))
                    for i in (self._controller.AverageGroup(group)):
                        print(i.__str__())
                elif inp==0:
                    break
                else:
                    print('Wrong command')
            except Exception as e:
                print(e)

SR=StudentRepo()
GR=GradeRepo()
C=Controller(SR,GR)
UI=UI(C)
UI.loop()
