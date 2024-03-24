#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	
	int tam;//tamanho do vetor
	int *v=NULL;//"ponteiro" q vai armazenar os valores
	int *p=NULL;//ponteiro de varredura
	double soma=0;//somatorio dos vetores
	int i;//contador
	
	cin>>tam;//entrando com o tamanho do vetor
	
	v=new int [tam];//"convertendo" ponteiro em vetor
	
	//entrando com valores e somando
	p=v;
	for(i=0;i<tam;i++){
		cin>>*p;
		soma+=*p;
		p++;
	}
	
	//mostrando a média
	cout<<fixed<<setprecision(2)<<soma/tam<<endl;
	
	delete[]v;
	return 0;
}