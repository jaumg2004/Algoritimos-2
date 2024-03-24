#include<iostream>
#include<list>
using namespace std;
int main(){
	
	list<int> estoque;//"ponteiro" para o estoque
	list<int>::iterator p;//"ponteiro" de varredura
	list<int> venda;//"ponteiro" para armazenar os produtor vendidos
	int x;//variaveis auxliares
	int n;//variavel de menu
	int tam;//tamanho da operação
	int i;//contador
	
	//inciando a operação
	cin>>tam;
	
	for(i=0; i<tam; i++){
		cin>>n;	
		switch(n){
			
		case 1:
			cin>>x;
			estoque.push_back(x);
			break;
		case 2:
			
			x=*estoque.begin();
			venda.push_front(x);
			estoque.pop_front();

			break;
		}
	}
	
	//saida das listas
	cout<<"Estoque: ";
	for(p=estoque.begin(); p!=estoque.end(); p++)
		cout<<*p<<" ";
	cout<<endl;
	
	cout<<"Venda: ";
	for(p=venda.begin(); p!=venda.end(); p++)
		cout<<*p<<" ";

	//removendo os elementos inseridos
	while(!estoque.empty())
		estoque.pop_front();
	
	while(!venda.empty())
		venda.pop_front();
	return 0;
}