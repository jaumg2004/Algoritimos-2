#include<iostream>
using namespace std;
// Esta função recebe um inteiro x
// e um vetor crescente v[0..n-1]
// e devolve um índice j em 0..n 
// tal que v[j-1] < x <= v[j].

int buscabinariainvertida(int x, int vetor[], int alto, int baixo){
	//x = variavel procurada
	//alto = posicao do vetor que contem a variavel de maior valor
	//baixo = posicao do vetor que contem a variavel de menor valor
	
	int meio;//literamente o meio do vetor, a media do 'alto' e 'baixo'
	bool busca=false;//condicao da busca
	
	while(baixo>=alto && busca==false){
		meio=(baixo+alto)/2;
		if(vetor[meio]>baixo){
			baixo=meio-1;
			busca=false;
		}
		if(vetor[meio]<alto){
			alto=meio+1;
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
	
	int i=0;//contador pra definir o tamanho do vetor
	int vet[10000];//vetor
	int chave;//variavel q vai ser procurada
	
	//entrada de dados
	cin>>vet[i];
	while(vet[i]>0){//condicao de variavel
		i++;
	    cin>>vet[i];	
	}
	cin>>chave;
	
	//chamando e comparando a funcao 'buscabinariainvertida'
	
	if(buscabinariainvertida(chave,vet,0,i)!=-1)
		cout<<chave<<" encontrada na posicao "<<buscabinariainvertida(chave,vet,0,i);
	else
		cout<<chave<<" nao encontrada";
	return 0;
}