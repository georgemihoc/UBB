class Student:
    def __init__(self,id,name,group):
        self._id=id
        self._name=name
        self._group=group

    def getID(self):
        return int(self._id)

    def getName(self):
        return self._name

    def getGroup(self):
        return int(self._group)

    def setID(self,new):
        self._id=new

    def setName(self,new):
        self._name=new

    def setGroup(self,new):
        self._group=new

    def __str__(self):
        return str(self._id)+","+str(self._name)+","+str(self._group)