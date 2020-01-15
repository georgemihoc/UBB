class Grade:
    def __init__(self,studentID,lab,labp,grade):
        self._id=studentID
        self._lab=lab
        self._problem=labp
        self._grade=grade

    def getID(self):
        return int(self._id)

    def getLab(self):
        return int(self._lab)

    def getProblem(self):
        return int(self._problem)

    def getGrade(self):
        return int(self._grade)

    def setLab(self,new):
        self._lab=new

    def setProblem(self,new):
        self._problem=new

    def setGrade(self,new):
        self._grade=new

    def __str__(self):
        return "Student ID:"+str(self._id)+" Lab#:"+str(self._lab)+" Problem:"+str(self.getProblem())+" Grade:"+str(self._grade)

    def str(self):
        return str(self._id)+","+str(self._lab)+","+str(self._problem)+","+str(self._grade)


