#include<iostream>
#include<iomanip>
using namespace std;
void bubbleSort(double vetor[], int tamanho)
{
    int i, j; // contadores
    double trab;
    bool troca;
    int limite;
    troca = true;
    limite = tamanho - 1;
    while (troca)
    {
        troca = false;
        for (i = 0; i < limite; i++)
	    if (vetor[i] > vetor[i + 1])
	    {
		trab = vetor[i];
		vetor[i] = vetor[i + 1];
		vetor[i + 1] = trab;
		j = i;
		troca = true;
	    }
	limite = j;
    }
}
int main(){
    double vet[20];//vetor
    int tam;//tamanho do vetor
    int i;//contador
    
    cin>>tam;//lendo o tamanho do vetor
    
    while(tam>20){//condição de variavel do tamanho
        cin>>tam;
    }
    
    for(i=0; i<tam; i++){//iniciando a tabela
        cin>>vet[i];
    }
    
     bubbleSort(vet,tam);//chamando a função
     
     //mostrando os valores do vetor
    for(i=0; i<tam; i++){
        cout<<fixed<<setprecision(1)<<vet[i]<<" ";
    }
    
    return 0;
}