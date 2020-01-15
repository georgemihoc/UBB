from Student import *

def StudentValidator(Student):
    if len(Student._name)==0:
        raise ValueError('Invalid Student')
    try:
        int(Student._group)
        int(Student._id)
    except Exception as e:
        raise ValueError('Invalid Student')