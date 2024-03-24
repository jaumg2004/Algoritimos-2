#include<iostream>
#include<list>
using namespace std;
int conta(list<int>lista){
	list<int>::iterator p;//ponteiro de varredura
	int i=0;//contador
	
	//contando os dados
	for(p=lista.begin();p!=lista.end();p++)
		i++;
	
	//retornando ao contador
	return i;
}
int main(){
	
	list<int>pilha;//declarando pilha
	int x;//variavel auxiliar
	
	//entrando com dados
	cin>>x;
	while(x>0){
		pilha.push_front(x);
		cin>>x;
    }
    
    //chamando e mostrando a função de conta
    cout<<conta(pilha);
    
    //apagando dados
    while(!pilha.empty())
    	pilha.pop_front();
    
	return 0;
}