#include <iostream>
#include <vector>
using namespace std;

int somme_consecutifs_max(vector<int>);
vector<size_t> lignes_max(vector<vector<int>>);
vector<vector<int>> tranches_max(vector<vector<int>>);

int main()
{
	vector<int> tabTestA = {0, 2, 2, 0};
	vector<int> tabTestB = {2, 3, 0, 0, 4};
	vector<int> tabTestC = {4, 0, 2, 3};
	vector<int> tabTestD = {0, 0, 0, 0};

	vector<vector<int>> tabTestF = {{2, 1, 0, 2, 0, 3, 2},
									{0, 1, 0, 7, 0},
									{1, 0, 1, 3, 2, 0, 3, 0, 4},
									{5, 0, 5},
									{1, 1, 1, 1, 1, 1, 1}};

	vector<vector<int>> tabTestE = {{2, 1, 0, 2},
									{0, 1, 0, 3},
									{1, 3, 0, 0},
									{0, 2, 2, 0}};

	vector<vector<int>> tabTestVide;

	vector<vector<int>> tabTestLigneVide = {{},
											{0, 1, 0, 7, 0},
											{1, 0, 1, 3, 2, 0, 3, 0, 4},
											{5, 0, 5},
											{1, 1, 1, 1, 1, 1, 1}};

	vector<vector<int>> tabTestLigneIdentique = {{0, 1, 0, 7, 0},
												 {0, 1, 0, 7, 0},
												 {0, 1, 0, 7, 0},
												 {0, 1, 0, 7, 0},
												 {0, 1, 0, 7, 0}};

	vector<vector<int>> tabTestNoZero = {
		{1, 7},
		{1, 1, 3, 2, 3, 4},
		{5, 5},
		{1, 1, 1, 1, 1, 1, 1}};

	cout << somme_consecutifs_max(tabTestA) << endl;
	cout << somme_consecutifs_max(tabTestB) << endl;
	cout << somme_consecutifs_max(tabTestC) << endl;
	cout << somme_consecutifs_max(tabTestD) << endl;

	cout << "{ ";
	for (auto j : lignes_max(tabTestE))
	{
		cout << j << ", ";
	}
	cout << "}" << endl;

	cout << "{ ";
	for (auto lignes : tranches_max(tabTestF))
	{
		for (auto j : lignes)
		{
			cout << j << ", ";
		}
		cout << endl;
	}
	cout << "}" << endl;

	cout << "{ ";
	for (auto lignes : tranches_max(tabTestVide))
	{
		for (auto j : lignes)
		{
			cout << j << ", ";
		}
		cout << endl;
	}
	cout << "}" << endl;

	cout << "{ ";
	for (auto lignes : tranches_max(tabTestLigneVide))
	{
		for (auto j : lignes)
		{
			cout << j << ", ";
		}
		cout << endl;
	}
	cout << "}" << endl;

	cout << "{ ";
	for (auto lignes : tranches_max(tabTestLigneIdentique))
	{
		for (auto j : lignes)
		{
			cout << j << ", ";
		}
		cout << endl;
	}
	cout << "}" << endl;

	cout << "{ ";
	for (auto lignes : tranches_max(tabTestNoZero))
	{
		for (auto j : lignes)
		{
			cout << j << ", ";
		}
		cout << endl;
	}
	cout << "}" << endl;

	return 0;
}

int somme_consecutifs_max(vector<int> tableauDontOnVeutExtraireLaSomme)
{
	int meilleurSomme = 0, sommeEnCours = 0;

	for (auto element : tableauDontOnVeutExtraireLaSomme)
	{
		if (element > 0)
		{
			sommeEnCours += element;
		}
		else
		{
			sommeEnCours = 0;
		}
		if (sommeEnCours > meilleurSomme)
		{
			meilleurSomme = sommeEnCours;
		}
	}
	return meilleurSomme;
}

vector<size_t> lignes_max(vector<vector<int>> tableauAEvaluer)
{
	vector<size_t> result;
	int meilleureSomme = 0;

	for (size_t i = 0; i < tableauAEvaluer.size(); i++)
	{
		int sommeConsecutive = somme_consecutifs_max(tableauAEvaluer[i]);
		if (sommeConsecutive == meilleureSomme)
		{
			result.push_back(i);
		}
		else
		{
			if (sommeConsecutive > meilleureSomme)
			{
				meilleureSomme = sommeConsecutive;
				result.clear();
				result.push_back(i);
			}
		}
	}

	return result;
}

vector<vector<int>> tranches_max(vector<vector<int>> tableauEnEntree)
{
	vector<size_t> indicesLignesMax = lignes_max(tableauEnEntree);
	vector<vector<int>> tranchesMax;
	for (auto indice : indicesLignesMax)
	{
		tranchesMax.push_back(tableauEnEntree[indice]);
	}
	return tranchesMax;
}
