#include<iostream>
using namespace std;
int main(){
	
	int i;//contador
	int tam;//tamanho do vetor
	int *v=NULL;//"ponteiro" q vai ser amarzenado os valores
	int *p=NULL;//ponteiro de varredura
	
	cin>>tam;//entrando com o tamanho do vetor
	
	v=new int [tam];//convertendo ponteiro em vetor
	
	//entrando com os valores
	p=v;
	for(i=0;i<tam;i++){
		cin>>*p;
		p++;
	}
	
	//mostrando os valores
	p=v;
	for(i=0;i<tam;i++){
		cout<<*p<<" ";
		p++;
	}
	
	delete[]v;
	return 0;
}