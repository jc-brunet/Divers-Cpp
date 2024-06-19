#include <iostream>
using namespace std;
int main() {
	float x; int y; float a, b, c, d;

	x = 2;
	y = 4;

	a = x+y;
	b=x-y;
	c=x*y;
	d=x/y;

	cout<<"La somme de "<<x<<" et "<<y<< " est: "<<a<<endl;
	cout<<"La différence de "<<x<<" et "<<y<< " est: "<<b<<endl;
	cout<<"Le produit de "<<x<<" et "<<y<< " est: "<<c<<endl;
	cout<<"La division de "<<x<<" et "<<y<< " est: "<<d<<endl;
}
