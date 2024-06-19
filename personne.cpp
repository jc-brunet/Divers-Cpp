#include <iostream>
using namespace std;

struct Personne
{
    double taille;
    int age;
    char sexe;
};

void affiche_personne(Personne const &);
void anniversaire(Personne &);
Personne naissance();

int main()
{
    Personne personne = naissance();

    affiche_personne(personne);

    anniversaire(personne);

    affiche_personne(personne);
    return 0;
}

void affiche_personne(Personne const &personne)
{
    cout << "Taille: " << personne.taille << endl;
    cout << "Age: " << personne.age << endl;
    cout << "Sexe: " << personne.sexe << endl;
}

void anniversaire(Personne &personne)
{
    ++(personne.age);
}

Personne naissance()
{
    Personne nouvellePersonne;
    cout << "Veuillez entrer l'âge" << endl;
    cin >> nouvellePersonne.age;
    cout << "Homme [M] ou Femme [F]" << endl;
    cin >> nouvellePersonne.sexe;
    cout << "Veuillez entrer la taille" << endl;
    cin >> nouvellePersonne.taille;

    return nouvellePersonne;
}