#include<iostream>
#include<list>
using namespace std;
int contar(list<int> lista){
	list<int>::iterator p;//"ponteiro" para varredura
	int i=0;//contador
	
	//varrendo a tabela
	for(p=lista.begin(); p!=lista.end(); p++)
		i++;
	
	//retornando contador
	return i;
}
int main(){
	
	list<int> lista;//"ponteiro" para a lista
	int x;//variavel auxiliar para a lista
	
	//inciando tabela
	cin>>x;
	while(x!=0){
		lista.push_back(x);
		cin>>x;
	}
	
	//chamando e recebendo função de contagem
	cout<<contar(lista);
	
	//removendo os elementod inseridos
	while(!lista.empty())
		lista.pop_front();
	return 0;
}