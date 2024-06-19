#include <iostream>
using namespace std;
int main() {
	const int BASE(4);
	float fromage(800.0);
	float eau(2.0);
	float ail(2.0);
	float pain (400.0);
	int nb_convives;
	
	cout<<"Combien de convives y aura-t-il pour votre fondue?"<<endl;
	cin>>nb_convives;

	cout<<"Pour faire une fondue fribourgeoise pour "<< nb_convives<<", il vous faut :"<<endl;
	cout<<"	-"<< fromage * nb_convives / BASE << " gr de vacherin Fribourgeois"<<endl;
	cout<<"	-"<< eau * nb_convives / BASE << " dl d'eau"<<endl;
	cout<<"	-"<< ail * nb_convives / BASE << " gousses d'ail"<<endl;
	cout<<"	-"<< pain * nb_convives / BASE << " gr de pain"<<endl;
	cout<<"-Du poivre à volonté!"<<endl;
	return 0;
}
