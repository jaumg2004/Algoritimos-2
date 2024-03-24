#include<iostream>
#include<list>
using namespace std;
int main(){
	
	list<int> fila;//"ponteiro" para lista ligada
	int x;//var aux para leitura dos dados
	
	for(int i=0; i<4; i++){
		cin>>x;
	    fila.push_back(x);//insere x no inicio
	}

	while(!fila.empty()){
	cout<<*fila.begin()<<endl;
	fila.pop_front();
	}

	return 0;
}