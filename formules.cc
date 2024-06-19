#include <iostream>
#include <cmath>
using namespace std;
int main()
{
double x(0.0);

while(true){
cout<<"Entrez un reel"<<endl;
cin>>x;

 if(x!=0){
	cout<<x/(1-exp(x))<<endl;
}else{
	cout<<"Expression 1 indefinie"<<endl;
}

if(x>0 && x!=1){
	cout<<x*log(x)*exp(2/(x-1))<<endl;
}else{
	cout<<"Expression 2 indefinie"<<endl;
}

if((x<=0 || x>=8) && x!=2){
	cout<<(-x-sqrt(x*x-8*x))/(2-x)<<endl;
}else{
	cout<<"Expression 3 indefinie"<<endl;
}
if(x!=0){
	if(sin(x)==(x/20)){
		cout<<x*log(x)*exp(2/(x-1))<<endl;
	}else{
		if(sin(x)<(x/20)){
			if((x*x-(1/x))<=1){
				cout<<x*log(x)*exp(2/(x-1))<<endl;
			}else{
				cout<<"Expression 4 indefinie"<<endl;
			}
		}else{
			if(x*x-(1/x)>=1){
				cout<<x*log(x)*exp(2/(x-1))<<endl;
			}else{
				cout<<"Expression 4 indefinie"<<endl;
			}
		}
	}
}else{
	cout<<"Expression 4 indefinie"<<endl;
}
}
	 
	 return 0;  }

