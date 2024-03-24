#include<iostream>
using namespace std;
int buscabinaria(int x, int vetor[], int alto, int baixo){
	
	int meio;
	bool busca=false;
	
	while(baixo>=alto && busca==false){
		meio=(alto+baixo)/2;
		if(vetor[meio]>x){
			alto=meio-1;
			busca=false;
		}
		if(vetor[meio]<x){
			baixo=meio+1;
			busca=false;
		}
		else{
			busca=true;
		}
	}
	if(busca)
		return meio;
	else
		return -1;
	
}
int main(){
	
	int vet[100];
	int chave;
	int i=0;
		
	cin>>vet[i];
	while(vet[i]!=-1 || i==100){
		i++;
		cin>>vet[i];
	}
	
	cin>>chave;
	

	if(buscabinaria(chave,vet,i,0)!=-1){
		cout<<chave<<" esta na posicao "<<buscabinaria(chave,vet,i,0);
	}
	else{
		cout<<chave<<" nao esta em nenhua posicao do vetor";
	}
	return 0;
}