#include<iostream>
#include<cstring>
#include<list>
using namespace std;
struct dado{
	int divida;
	char nome[51];
};
int main(){
	
	list<dado> cliente;//"ponteiro" da lista de clientes
	list<dado>::iterator p;//"ponteiro" auxiliar de varredura
	int n;//número de clientes
	int i;//contador
	char nome[51];//string auxiliar
	dado x;//variavel auxiliar da struct
	
	//entrando com os dados dos clientes
	
	cin>>n;
	for(i=0; i<n; i++){
		cin.ignore();
		cin.getline(x.nome,51);
		cin>>x.divida;
		cliente.push_back(x);
	}
	
	//apagando o nome do cliente q quitou a divida
	cin.ignore();
	cin.getline(nome,51);
	for(p=cliente.begin();p!=cliente.end();p++){
		if(strcmp(nome,p->nome)!=0){
			cout<<p->nome<<endl;
		    cout<<p->divida<<endl;
		}
	}
	
	//apagando os dados dos clientes
	while(!cliente.empty())
		cliente.pop_front();
	return 0;
}