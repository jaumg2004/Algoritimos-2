#include<iostream>
using namespace std;
int main(){
	
	int tam;//tamanho do vetor
	int *v=NULL;//"ponteiro" q vai armazenar os valores
	int *p=NULL;//ponteiro de varredura
	int maior=-99999;//variavel q vai armazenar o maior valor
	int i;//contador
	
	cin>>tam;//entrando com tamanho do vetor
	
	v=new int [tam];//"convertendo" ponteiro em vetor
	
	//entrando com os valores e comparando
	p=v;
	for(i=0;i<tam;i++){
		cin>>*p;
		if(*p>maior)
			maior=*p;
		p++;
	}
	
	//mostrando o maior valor
	cout<<maior;
	
	delete[]v;
	return 0;
}