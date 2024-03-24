#include<iostream>
#include<list>
using namespace std;
int main(){
	
	list<int> pilha;//"ponteiro" para lista ligada
	int x;//var aux para leitura dos dados
	
	for(int i=0; i<4; i++){
		cin>>x;
		pilha.push_front(x);//insere x no inicio
	}
	
	while(!pilha.empty()){
	cout<<*pilha.begin()<<endl;
	pilha.pop_front();
	}

	return 0;
}