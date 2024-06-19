#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  if (fin < 0 or fin > 24 or debut < 0 or debut > 24)
  {
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
  }
  else
  {
    if (fin == debut)
    {
      cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    }
    else
    {
      if (fin < debut)
      {
        cout << "Bizarre, le début de la location est après la fin ..." << endl;
      }
      else
      {
        int prix(fin - debut), dureeDeuxFrancs(0);
        if(fin<7 and debut<)
        }
        cout << "Vous avez loué votre vélo pendant" << endl;

        cout << 2*(fin - debut) - prix << " heure(s) au tarif horaire de "
             << "1 franc(s)" << endl;

        cout << prix - (fin - debut) << " heure(s) au tarif horaire de "
             << "2 franc(s)" << endl;

        cout << "Le montant total à payer est de "
             << prix << " franc(s)." << endl;
      }
    }
  }

   /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
