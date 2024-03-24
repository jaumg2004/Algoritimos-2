#include<iostream>
#include<list>
using namespace std;
bool procurado(list<int>lista, int y){
	
	list<int>::iterator p;//ponteiro de varredura
	
	//procurando dado
	for(p=lista.begin();p!=lista.end();p++){
		if(*p==y){
			return true;
		}
	}
	return false	
}

int main(){
	
	list<int>pilha;//declarando lista
	int x,y;//variaveis auxiliares
	
	//entrando com dados
	cin>>x;
	while(x>0){
		pilha.push_front(x);
		cin>>x;
	}
	
	cin>>y;//dado q vai ser procurado
	
	//chamando função de busca
	if(procurado(pilha,y))
		cout<<"Encontrado"<<endl;
	else
		cout<<"Nao encontrado"<<endl;
	
	//apagando dados
	while(!pilha.empty())
		pilha.pop_front();
	
	return 0;
}