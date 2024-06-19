#include <iostream>
using namespace std;
int main()
{
double x(0);
while(true){
cout<<"Entrez un réel"<<endl;
cin>>x;

if((!(x<2) && x<3)||(x>0 && !(x>1))||(!(x<-10) && !(x>-2))){
	cout<<"x appartient à I"<<endl;
}else{
	cout<<"x n'appartient pas à I"<<endl;
}
}
	
return 0;
}

