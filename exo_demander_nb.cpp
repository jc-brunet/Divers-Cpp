#include <iostream>
using namespace std;

int demander_nb(int, int);

int main()
{

    int res = demander_nb(1, 10);
    (cout <<);
    return 0;
}

int demander_nb(int borneInf, int borneSup)
{
    int nombreEntre;
    cout << "Entrez un nombre compris entre " << borneInf << " et " << borneSup<<endl;
    return(cin>>nombreEntre,nombreEntre);
}