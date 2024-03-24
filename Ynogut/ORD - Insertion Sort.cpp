#include<iostream>
using namespace std;
void bolha(int vet[], int tamanho){
	bool troca=true;
	int trab;
	
	
	while(troca){
		troca=false;
		for(int j=tamanho-1; j>=0; j--){
			if(vet[j+1]>vet[j]){
				trab=vet[j+1];
				vet[j+1]=vet[j];
				vet[j]=trab;
				troca=true;
			}
		}
	}
	for(int i=0; i<tamanho; i++){
		cout<<vet[i]<<" ";
	}
}
int main()
{
	int vet[1000], i=0;
    
    
	cin>>vet[i];
	while(vet[i]!=0){
		i++;
		cin>>vet[i];
	}
	bolha(vet, i);
	
	return 0;
}