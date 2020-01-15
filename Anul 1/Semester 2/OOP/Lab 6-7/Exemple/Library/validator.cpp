#include "validator.h"

void BookValidator::validate(const Book& p) {
	vector<string> msgs;
	if (p.getYear() <= 0) msgs.push_back("An negativ!!!");
	if (p.getTitle().size() == 0) msgs.push_back("Titlu vid!!!");
	if (p.getWriter().size() == 0) msgs.push_back("Autor vid!!!");
	if (p.getGenre().size() == 0) msgs.push_back("Gen vid!!!");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}

ostream& operator<<(ostream& out, const ValidateException& ex) {for (const auto& msg : ex.msgs) {out << msg<<" ";}return out;}