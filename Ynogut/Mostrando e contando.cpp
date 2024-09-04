#include<iostream>
using namespace std;
void bubblesort(int vetor[], int tam){
	int aux;//variavel auxiliar
	int cont=0;//contador pra troca
	bool troca=true;
	
	while(troca){
		troca=false;
		for(int j=0; j<tam-1; j++){//declarando contador dentro do 'for'
		if(vetor[j]>vetor[j+1]){
			aux=vetor[j];
			cout<<"New aux: "<<aux<<endl;//mostrando o valor de aux
			vetor[j]=vetor[j+1];
			vetor[j+1]=aux;
			cont++;
			troca=true;
		}
	}
	}
	cout<<cont<<endl;
	for(int i=0; i<tam; i++){//declarando contador dentro do 'for'
		cout<<vetor[i]<<" ";
	}
}
int main(){
	
	int tam;//tamanho do vetor
	int vet[10000];//vetor
	
	//entrada de dados
	
	cin>>tam;
	
	for(int i=0; i<tam; i++){//declarando contador dentro do 'for'
		cin>>vet[i];
	}
	bubblesort(vet, tam);//chamando a funcao
	return 0;
}
