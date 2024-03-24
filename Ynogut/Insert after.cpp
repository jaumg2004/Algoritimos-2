#include<iostream>
#include<list>
using namespace std;
int main(){
	
	list<int>pilha;//declarando lista
	list<int>::iterator p;//ponteiro auxiliar
	int i,x,y;//variaveis auxliares
	
	//entrando com os dados
	cin>>x;
	while(x!=-1){
		pilha.push_front(x);
		cin>>x;
	}
	
	//inserindo novo dado
	cin>>i>>y;
	for(p=pilha.begin();p!=pilha.end();p++){
		if(*p==i){
			p++;
			pilha.insert(p,y);
		}
	}
	
	//mostrando ps dados da pilha
	for(p=pilha.begin();p!=pilha.end();p++){
		cout<<*p<<" ";
	}
	
	//apagando dados
	while(!pilha.empty())
		pilha.pop_front();
	return 0;
}