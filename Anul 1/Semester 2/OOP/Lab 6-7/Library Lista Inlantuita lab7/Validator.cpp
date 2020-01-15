#include "Validator.h"



Validator::Validator()
{
}



/*ostream& operator<<(ostream& out, const ValidationException& ex) {
	for (const auto& msg : ex.msgs) {
		out << msg << " ";
	}
	return out;
}*/

void Validator::valideaza(const Book& p) {
	vector<string> errors;
	if (p.get_titlu().size() == 0) errors.push_back("titlule este invalid!");
	if (p.get_gen().size() == 0) errors.push_back("genul este invalid!");
	if (p.get_autor().size() == 0) errors.push_back("autorul este invalid!");
	if (p.get_an() < 0) errors.push_back("anul este invalid!");
	if (errors.size() > 0)
		throw ValidationException(errors);
}