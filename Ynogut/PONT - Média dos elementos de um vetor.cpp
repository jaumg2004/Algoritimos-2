#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int tam, *v=NULL, *p=NULL;
	double soma=0;
	
	
	cin>>tam;
	v=new int[tam];
	p=v;
	for(int i=0; i<tam; i++){
		cin>>*p;
		soma+=*p;
		p++;
	}
	cout<<fixed<<setprecision(2)<<soma/tam<<endl;
	delete[]v;
	return 0;
}