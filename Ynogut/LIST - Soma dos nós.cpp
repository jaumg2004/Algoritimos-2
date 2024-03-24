#include<iostream>
#include<list>
using namespace std;
int soma(list<int> lista){
	list<int>::iterator p;//"ponteiro" de varredura
	int soma=0;//variavel q vai armazenar o valor da soma
	
	//inciando varredura
	for(p=lista.begin(); p!=lista.end(); p++)
		soma+=*p;
	
	//retornadno o valor da soma
	
	return soma;
}
int main(){
	
	list<int> lista;//"ponteiro" para a lista
	int x;//variavel aux para leitura 
	
	//inicianco tabela
	cin>>x;
	while(x!=0){
		lista.push_back(x);
		cin>>x;
	}
	
	//chamando a função soma e mostrando o resultado
	cout<<soma(lista);
	
	//removendo os elementod inseridos
	while(!lista.empty())
		lista.pop_front();
	return 0;
}
