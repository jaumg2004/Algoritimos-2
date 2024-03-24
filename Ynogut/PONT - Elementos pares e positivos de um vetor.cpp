#include<iostream>
using namespace std;
int main(){
	int tam, *v=NULL, *p=NULL, cont=0;
	
	cin>>tam;
	v=new int[tam];
	p=v;
	for(int i=0; i<tam; i++){
		cin>>*p;
		p++;
	}
	p=v;
	for(int j=0; j<tam; j++){
		if(*p>0 && *p%2==0)
			cont++;
		p++;
	}
	cout<<cont;
	delete[]v;
	return 0;
}