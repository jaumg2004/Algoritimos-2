#include<iostream>
using namespace std;
int bolha(int vet[], int tamanho){
	bool troca=true;
	int trab;
	int cont=0;
	
	while(troca){
		troca=false;
		for(int j=0; j<tamanho-1; j++){
			if(vet[j]>vet[j+1]){
				trab=vet[j];
				cout<<"New trab:"<<trab<<endl;
				vet[j]=vet[j+1];
				vet[j+1]=trab;
				cont++;
				troca=true;
			}
		}
	}
	return cont;
}
int main()
{
	int vet[1000], x, contador;
    
	cin>>x;
	for(int i=0; i<x; i++)
		cin>>vet[i];
	
	contador=bolha(vet, x);
	cout<<"Contador:"<<contador;
	
	return 0;
}