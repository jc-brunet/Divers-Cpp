#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

typedef vector<vector<int>> Carte;

struct Position
{
  size_t i;
  size_t j;
};

bool binaire(Carte const &carte);
void affiche(Carte const &carte);
bool verifie_et_modifie(Carte &carte);
double longueur_cloture(Carte const &carte,
                        double echelle = 2.5);
void marque_composantes(Carte &carte);
void ajoute_unique(vector<int> &ensemble, int valeur);
bool convexite_lignes(Carte &carte, vector<int> const &labels_bords);
bool convexite_lignes(Carte &carte);

// cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
// cout << "bord extérieur entrant trouvé en position [";
// cout << "][";
// cout << "]" << endl;

// cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
bool binaire(Carte const &carte)
{
  bool result = true;
  for (auto ligne : carte)
  {
    for (auto element : ligne)
    {
      result &= (element == 0 || element == 1);
    }
  }
  return result;
}

void affiche(Carte const &carte)
{
  for (auto ligne : carte)
  {
    for (auto element : ligne)
    {
      cout << element;
    }
    cout << endl;
  }

  cout << endl
       << "----" << endl;
}

bool verifie_et_modifie(Carte &carte)
{

  if (!binaire(carte))
  {
    cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
    return false;
  }

  if (!convexite_lignes(carte))
  {

    return false;
  }

  for (auto &ligne : carte)
  {
    for (size_t i = 1; i < ligne.size(); i++)
    {
      if (ligne[i] != 1 && ligne[i - 1] == 1)
      {
        // On vérifie si ligne[i] est un étang ou un bord
        int indexADroite = i + 1;
        while ((indexADroite < ligne.size()))
        {
          if (ligne[indexADroite] == 1)
          {
            ligne[i] = 1;
            break;
            break;
            break;
          }
          indexADroite++;
        }
      }
    }
  }
  return true;
}

double longueur_cloture(Carte const &carte,
                        double echelle)
{
  double perimetreMathematique = 0.0;
  for (size_t i = 0; i < carte.size(); i++)
  {
    for (size_t j = 0; j < carte[i].size(); j++)
    {
      if (carte[i][j] == 1)
      {
        if (i == 0 || carte[i - 1][j] != 1)
        {
          perimetreMathematique++;
        }
        if (i == carte.size() - 1 || carte[i + 1][j] != 1)
        {
          perimetreMathematique++;
        }
        if (j == 0 || carte[i][j - 1] != 1)
        {
          perimetreMathematique++;
        }
        if (j == carte[i].size() - 1 || carte[i][j + 1] != 1)
        {
          perimetreMathematique++;
        }
      }
    }
  }
  return perimetreMathematique * echelle;
}

void marque_composantes(Carte &carte)
{
  int composante = 1;
  vector<Position> pointsEnCoursDeTraitement;

  for (size_t i = 0; i < carte.size(); i++)
  {
    for (size_t j = 0; j < carte[i].size(); j++)
    {
      if (carte[i][j] == 0)
      {
        composante++;
        Position positionCourante({i, j});
        pointsEnCoursDeTraitement.push_back(positionCourante);
        while (!pointsEnCoursDeTraitement.empty())
        {
          Position pointATraiter = pointsEnCoursDeTraitement[pointsEnCoursDeTraitement.size() - 1];
          pointsEnCoursDeTraitement.pop_back();
          if (carte[pointATraiter.i][pointATraiter.j] == 0)
          {
            carte[pointATraiter.i][pointATraiter.j] = composante;
            if (pointATraiter.i > 0 && carte[pointATraiter.i - 1][pointATraiter.j] == 0)
            {
              Position voisinAAjouter = {pointATraiter.i - 1, pointATraiter.j};
              pointsEnCoursDeTraitement.push_back(voisinAAjouter);
            }
            if (pointATraiter.i < carte.size() - 1 && carte[pointATraiter.i + 1][pointATraiter.j] == 0)
            {
              Position voisinAAjouter = {pointATraiter.i + 1, pointATraiter.j};
              pointsEnCoursDeTraitement.push_back(voisinAAjouter);
            }
            if (pointATraiter.j > 0 && carte[pointATraiter.i][pointATraiter.j - 1] == 0)
            {
              Position voisinAAjouter = {pointATraiter.i, pointATraiter.j - 1};
              pointsEnCoursDeTraitement.push_back(voisinAAjouter);
            }
            if (pointATraiter.j < carte[i].size() - 1 && carte[pointATraiter.i][pointATraiter.j + 1] == 0)
            {
              Position voisinAAjouter = {pointATraiter.i, pointATraiter.j + 1};
              pointsEnCoursDeTraitement.push_back(voisinAAjouter);
            }
          }
        }
      }
    }
  }
}

void ajoute_unique(vector<int> &ensemble, int valeur)
{
  bool isValeurPresente = false;
  for (auto elementEnsemble : ensemble)
  {
    isValeurPresente |= (valeur == elementEnsemble);
    if (isValeurPresente)
    {
      break;
    }
  }
  if (!isValeurPresente)
  {
    ensemble.push_back(valeur);
  }
}

bool convexite_lignes(Carte &carte, vector<int> const &labels_bords)
{
  for (int i = 0; i < carte.size(); i++)
  {
    int jBegin = 0;

    while (jBegin < carte[i].size() && carte[i][jBegin] != 1)
    {
      jBegin++;
    }
    int jEnd = carte[i].size() - 1;
    while (jEnd >= 0 && carte[i][jEnd] != 1)
    {
      jEnd--;
    }
    if (jBegin <= jEnd)
    {
      for (int k = jBegin; k <= jEnd; k++)
      {
        if (carte[i][k] != 1)
        {
          for (auto labelBords : labels_bords)
          {
            if (carte[i][k] == labelBords)
            {
              cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
              cout << "bord extérieur entrant trouvé en position [";
              cout << i;
              cout << "][";
              cout << k;
              cout << "]" << endl;

              return false;
            }
          }
        }
      }
    }
  }
  return true;
}

bool convexite_lignes(Carte &carte)
{
  marque_composantes(carte);
  vector<int> labels_bords;
  //TODO: 1ere et derniere ligne!!
  for (auto ligne : carte)
  {
    int i = 0;

    while (i < ligne.size() && ligne[i] != 1)
    {
      ajoute_unique(labels_bords, ligne[i]);
      i++;
    }
    i = ligne.size() - 1;
    while (i >= 0 && ligne[i] != 1)
    {
      ajoute_unique(labels_bords, ligne[i]);
      i--;
    }
  }
  return (convexite_lignes(carte, labels_bords));
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  cout << "Carte au départ :" << endl;
  affiche(carte);

  carte={{1,1,1},{1,0,1}};
  convexite_lignes(carte);
  affiche(carte);

  if (verifie_et_modifie(carte))
  {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
