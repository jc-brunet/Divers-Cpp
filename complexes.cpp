#include <iostream>
#include <cctype>
using namespace std;

struct Complexe
{
	double partieReelle;
	double partieImaginaire;
};

void affiche(Complexe);
Complexe addition(Complexe, Complexe);
Complexe soustraction(Complexe, Complexe);
Complexe multiplication(Complexe, Complexe);
Complexe division(Complexe, Complexe);

void afficheResultatsOperations(const Complexe &complexeUn, const Complexe &complexeDeux);

int main()
{
	Complexe complexeUn = {0, 1};
	Complexe complexeDeux = {0, 1};

	afficheResultatsOperations(complexeUn, complexeDeux);

	cout << "salut" << endl;

	Complexe complexeTrois = {1, 1};
	Complexe complexeQuatre = {1, 1};

	afficheResultatsOperations(complexeTrois, complexeQuatre);

	cout << "salut" << endl;

	Complexe complexeCinq = {0, 2};
	Complexe complexeSix = {0, 1};

	afficheResultatsOperations(complexeCinq, complexeSix);

	cout << "salut" << endl;

	complexeCinq = {2, -3};
	complexeSix = {1, 1};

	afficheResultatsOperations(complexeCinq, complexeSix);
	return 0;
}

void afficheResultatsOperations(const Complexe &complexeUn, const Complexe &complexeDeux)
{
	affiche(complexeUn);
	cout << " + ";
	affiche(complexeDeux);
	cout << "=";
	affiche(addition(complexeUn, complexeDeux));
	cout << endl;

	affiche(complexeUn);
	cout << " - ";
	affiche(complexeDeux);
	cout << "=";
	affiche(soustraction(complexeUn, complexeDeux));
	cout << endl;

	affiche(complexeUn);
	cout << " * ";
	affiche(complexeDeux);
	cout << "=";
	affiche(multiplication(complexeUn, complexeDeux));
	cout << endl;

	affiche(complexeUn);
	cout << " / ";
	affiche(complexeDeux);
	cout << "=";
	affiche(division(complexeUn, complexeDeux));
	cout << endl;
}

void affiche(Complexe complexe)
{
	cout << complexe.partieReelle << "+" << complexe.partieImaginaire << "i";
}

Complexe addition(Complexe complexeUn, Complexe complexeDeux)
{
	return Complexe({complexeUn.partieReelle + complexeDeux.partieReelle, complexeUn.partieImaginaire + complexeDeux.partieImaginaire});
}

Complexe soustraction(Complexe complexeUn, Complexe complexeDeux)
{
	return Complexe({complexeUn.partieReelle - complexeDeux.partieReelle, complexeUn.partieImaginaire - complexeDeux.partieImaginaire});
}

Complexe multiplication(Complexe complexeUn, Complexe complexeDeux)
{
	double x = complexeUn.partieReelle;
	double xPrime = complexeDeux.partieReelle;
	double y = complexeUn.partieImaginaire;
	double yPrime = complexeDeux.partieImaginaire;
	return Complexe({x * xPrime - y * yPrime, x * yPrime + y * xPrime});
}

Complexe division(Complexe complexeUn, Complexe complexeDeux)
{
	double x = complexeUn.partieReelle;
	double xPrime = complexeDeux.partieReelle;
	double y = complexeUn.partieImaginaire;
	double yPrime = complexeDeux.partieImaginaire;
	return Complexe({(x * xPrime + y * yPrime) / (xPrime * xPrime + yPrime * yPrime), (y * xPrime - x * yPrime) / (xPrime * xPrime + yPrime * yPrime)});
}
