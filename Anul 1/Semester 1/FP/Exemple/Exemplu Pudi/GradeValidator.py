from Grade import *

def GradeValidator(Grade):
    try:
        int(Grade._id)
        int(Grade._lab)
        int(Grade._grade)
        int(Grade._problem)
    except Exception as e:
        raise Exception("Grade is not valid")
    if int(Grade._grade)<1 or int(Grade._grade)>10:
        raise Exception("Grade is not valid")
