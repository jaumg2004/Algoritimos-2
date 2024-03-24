#include<iostream>
using namespace std;
int main(){
	
	int tam;//tamanho do vetor
	int *v=NULL;//"ponteiro" q vai armazenar os valores
	int *p=NULL;//ponteiro de varredura
	int i, cont=0;//contadores
	
	cin>>tam;//entrando com tamanho do vetor
	
	v=new int [tam];//"convertendo" ponteiro em vetor
	
	//entrando com os valores
	p=v;
	for(i=0;i<tam;i++){
		cin<<*p;
		p++;
	}
	
	//contando os valores positivos e pares
	p=v;
	for(i=0;i<tam;i++){
		if(p>0 && p%2==0)
			cont++;
		p++;
	}
	cout<<cont;
	
	delete[]v;
	return 0;
}