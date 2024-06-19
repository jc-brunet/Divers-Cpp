#include <iostream>
using namespace std;
int main() {
	double poids(88);
	double taille(1.80);
	
	
	cout<<"Entrez votre poids"<<endl;
	cin>>poids;
	cout<<"Entrez votre taille"<<endl;
	cin>>taille;
	double imc(poids/(taille*taille));
	
	cout << "Pour " << poids << "kg et " << taille << "m, l'imc est de " << imc << endl;
return 0;
}

