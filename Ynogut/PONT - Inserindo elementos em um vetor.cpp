#include<iostream>
using namespace std;
int main(){
	int tam, *v=NULL, *p=NULL;
	v=new int[1000];
	
	cin>>tam;
	p=v;
	for(int i=0; i<tam; i++){
		cin>>*p;
		p++;
	}
	p=v;	
	for(int i=0; i<tam; i++){
		cout<<*p<<" ";
		p++;
	}
		
	delete[]v;
	return 0;
}