#include<iostream>
using namespace std;
int main()
{
	double kg, h;
	
	cin>>kg;
	cin>>h;
	
	if(kg/(h*h)<18.5)
		cout<<"Baixo peso"<<endl;
	if(kg/(h*h)>=18.5 && kg/(h*h)<22)
		cout<<"Normal"<<endl;
	if(kg/(h*h)>=22 && kg/(h*h)<30)
		cout<<"Sobrepeso"<<endl;
	if(kg/(h*h)>=30)
		cout<<"Obeso"<<endl;
	
	return 0;
}