#include<iostream>
#include<cmath>
using namespace std;
void quickSort(int vetor[], int i, int j){
	int trab, esq, dir, pivo;
	dir=j;
	esq=i;
	pivo=vetor[(int)round((esq+dir)/2.0)];
	
	do{
		while(vetor[esq]<pivo)
			esq++;
		while(vetor[dir]>pivo)
			dir--;
		if(esq<=dir){
			trab=vetor[esq];
			vetor[esq]=vetor[dir];
			vetor[dir]=trab;
			esq++;
			dir--;
		}
	}while(esq<=dir);
	
	if(dir-i>=0)
		quickSort(vetor, i, dir);
	if(j-esq>=0)
		quickSort(vetor, esq, j);
}
int main()
{
	int i=0, vet[10000], aux, tam;
	
	cin>>aux;
	while(aux!=-1){
		vet[i]=aux;
		i++;
		cin>>aux;
	}
	tam=i-1;
	quickSort(vet, 0, tam);
	
	for(int k=0; k<i; k++)
		cout<<vet[k]<<" ";
	return 0;
}