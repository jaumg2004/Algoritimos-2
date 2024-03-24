#include<iostream>
#include<list>
using namespace std;
bool encontrar(list<int> lista, int x){
	list<int>::iterator p;//"ponteiro" para varrer a lista
	int cont=0;//contador auxiliar
	
	//incicando a varredura
	for(p=lista.begin(); p!=lista.end(); p++){
		if(*p==x)
			cont++;
	}
	
	//retornadno verdadeiro ou falso
	
	if(cont>0)
		return true;
	else
		return false;
}
int main(){
	
	list<int> lista;//"ponteiro" para a lista
	int x;//variavel auxiliar para leitura
	int n;//variavel q vai ser encontrada
	
	//lendo e inserindo elementos na lista
	cin>>x;
	while(x>0){

		lista.push_back(x);
		cin>>x;
	}
	
	cin>>n;//entrando com a variavel q vai ser procurada
	
	encontrar(lista,n);//chamando a variavel de busca
	
	if(encontrar(lista,n))
		cout<<"Encontrado"<<endl;
	else
		cout<<"Nao encontrado"<<endl;	
	
	//removendo os elementod inseridos
	while(!lista.empty())
		lista.pop_front();
	return 0;
}