#include<iostream>
#include<list>
using namespace std;
int soma(list<int>lista){
	list<int>::iterator p;//"ponteiro" de varredura
	int soma=0;//somatorio
	
	//somando os valores
	for(p=lista.begin();p!=lista.end();p++){
		soma+=*p;
	}
	
	//retornando o somatorio
	return soma;
}
int main(){
	
	list<int>pilha;//declarando lista
	int x;//variavel auxiliar
	
	cin>>tam;//entrando com o tamanho da lista
	
	//entrando com os dados
	cin>>x
	while(x>0){
		pilha.push_front(x);
		cin>>x;
	}
	
	//chamando e mostrando a função de soma
	cout<<soma(pilha)<<endl;
	
	//apagando os dados da pilha
	while(!pilha.empty())
		pilha.pop_front();
	
	return 0;
}