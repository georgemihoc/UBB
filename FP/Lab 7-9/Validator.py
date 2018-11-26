from Errors import ValidError


class PersonValidator(object):

    def valideazaPerson(self, person):
        erori = ""
        if person.get_pid() < 0:
            erori += "id invalid!\n"
        if person.get_nume() == "" or person.get_nume()[0] != person.get_nume()[0].upper() or person.get_nume()[1:] != person.get_nume()[1:].lower() or not (person.get_nume()[0:].isalpha()):
            erori += "nume invalid!\n"
        if len(erori) > 0:
            raise ValidError(erori)


class EventValidator(object):

    def valideazaEvent(self, event):
        erori = ""
        if event.get_id() < 0:
            erori += "id invalid!\n"
        if event.get_data() == "":
            erori += "data invalida!\n"
        if event.get_timp() < 0:
            erori += "timp invalid!\n"
        if event.get_desc() == "":
            erori += "descriere invalida!\n"
        if len(erori) > 0:
            raise ValidError(erori)


class AsignValidator(object):

    def valideazaAsign(self, asignare):
        erori = ""
        if asignare.get_pid() < 0:
            erori += "id persoana invalid!\n"
        if asignare.get_eid() < 0:
            erori += "id event invalid!\n"
        if len(erori) > 0:
            raise ValidError(erori)


