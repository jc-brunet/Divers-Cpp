#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

struct QCM
{
	string question;
	vector<string> reponses;
	int solution;
};

struct Examen
{
	vector<QCM> questions;
};

void affiche(QCM);
int demander_nombre(int, int);
int poser_question(QCM);
Examen creer_examen();
void affiche(Examen);

int main()
{
	vector<string> reponses = {"32", "de 6 a 10", "beaucoup", "24", "2"};
	QCM qcmUn = {"Combien de dents possède un éléphant adulte ?", reponses, 1};
	int reponseUn = poser_question(qcmUn);
	cout << "Réponse de l'utilisateur: " << reponseUn << endl;
	Examen examen = creer_examen();
	affiche(examen);

	return 0;
}

void affiche(QCM qcm)
{
	cout << qcm.question << endl;
	for (int i = 0; i < qcm.reponses.size(); ++i)
	{
		cout << i + 1 << " - " << qcm.reponses[i] << endl;
	}
};

int demander_nombre(int min, int max)
{
	int reponse;
	cout << "Entrez votre réponse: " << endl;
	cin >> reponse;
	while (reponse < min or reponse > max)
	{
		cout << "Votre réponse doit etre comprise entre " << min << " et " << max << endl;
		cin >> reponse;
	}
	return reponse;
}
int poser_question(QCM question)
{
	affiche(question);
	return demander_nombre(0, question.reponses.size());
};
Examen creer_examen()
{
	Examen examen;
	examen.questions = {// Question 1
						{
							"Combien de dents possède un éléphant adulte",
							{"32", "de 6 à 10", "beaucoup", "24", "2"},
							2 // réponse
						},
						// Question 2
						{
							"Laquelle des instructions suivantes est un prototype de fonction", {"int f(0);", "int f(int 0);", "int f(int i);", "int f(i);"},
							3 // réponse
						},
						// Question 3
						{
							"Qui pose des questions stupides",
							{"le prof. de math",
							 "mon copain/ma copine",
							 "le prof. de physique",
							 "moi",
							 "le prof. d'info",
							 "personne, il n'y a pas de question stupide",
							 "les sondages"},
							6 // réponse
						}};
	return examen;
}

void affiche(Examen examen)
{
	int reponseEnCours = -1;
	int nombreBonnesReponses = 0;
	for (auto question : examen.questions)
	{
		reponseEnCours = poser_question(question);
		if (reponseEnCours  == question.solution)
		{
			nombreBonnesReponses++;
		}
	}
	cout << "Vous avez obtenu " << nombreBonnesReponses << " bonnes réponses!" << endl;
}