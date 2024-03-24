#include<iostream>
#include<list>
using namespace std;
int main(){
	
	list<int> lista;//"ponteiro" para lista
	list<int>::iterator p;//"ponteiro" auxiliar
	int x, y, i;//variaveis auxiliares

	//iniciando tabela
	cin>>x;
	while(x!=-1){
		lista.push_front(x);
		i++;
		cin>>x;
	}
	
	//inserindo nova variavel na pilha
	cin>>i>>y;
	
	
	for(p=lista.begin();p!=lista.end();p++){
		if(*p==i){
			p++;
			lista.insert(p,y);
		}
	}
	
	for(p=lista.begin();p!=lista.end();p++){
		cout<<*p<<" ";
	}
	//removendo os elementos inseridos
	while(!lista.empty())
		lista.pop_front();
	
	return 0;
}