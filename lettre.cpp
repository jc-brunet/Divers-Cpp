#include <iostream>
#include <cctype>
using namespace std;

void genereLettre(const bool &, const string &, const string &, const string &, const string &, const string &, const string &);
string capitalize(string);

int main()
{
	genereLettre(false, "mireille", "votre cours", "12", "18", "amicalement", "john");
	genereLettre(true, "john", "votre demande de rendez-vous", "16", "12", "sincerement", "mireille");
	return 0;
}

void genereLettre(const bool &masculin, const string &destinataire, const string &sujet, const string &dateMois, const string &dateJour, const string &politesse, const string &auteur)
{
	string motDintro = "cher";
	motDintro = masculin ? motDintro : motDintro + 'e';

	cout << "Bonjour " << motDintro << " " << capitalize(destinataire) << endl;
	cout << "Je vous écris à propos de " << sujet << endl;
	cout << "Il faudrait que nous nous voyons le " << dateJour << "/" << dateMois << " pour en discuter." << endl;
	cout << "Donnez - moi vite de vos nouvelles!" << endl;
	cout << capitalize(politesse)
		 << ", " << capitalize(auteur) << "." << endl;
}

string capitalize(string stringToCapitalize)
{
	stringToCapitalize[0] = char(toupper(stringToCapitalize[0]));
	return stringToCapitalize;
}
