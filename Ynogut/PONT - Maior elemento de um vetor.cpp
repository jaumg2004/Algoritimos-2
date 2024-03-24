#include<iostream>
using namespace std;
int main(){
	int tam, *v=NULL, *p=NULL, maior=-99999;
	
	cin>>tam;
	v=new int[tam];
	p=v;
	for(int i=0; i<tam; i++)
		cin>>v[i];
	p=v;
	for(int j=0; j<tam; j++){
		if(*p>maior)
			maior=*p;
		p++;
	}
	cout<<maior;
	delete[]v;
	return 0;
}