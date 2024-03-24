#include<iostream>
#include<list>
using namespace std;
void bubblesort(list<int> ordem, int alto){
	int *v;//"ponteiro" auxiliar
	int k;//contador
	int aux;//variavel auxiliar
	v=new int [alto];//convertendo "ponteiro" pra vetor
	bool troca=true;
	
	*v=*ordem.begin();
	while(troca){
		troca=false;
		for(k=0;k<alto-1; k++){
			if(v[k]>v[k+1]){
				aux=v[k+1];
				v[k+1]=v[k];
				v[k]=aux;
				troca=true;
			}
		}
	}
}
int main(){
	
	list<int> lista1;//"ponteiro" para a lista 1
	list<int> lista2;//"ponteiro" para a lista 2
	list<int>::iterator p;//"ponteiro" de varredura da lista 1
	list<int>::iterator u;//"ponteiro" de varredura da lista 2
	int x;//variavel auxiliar da primeira lista
	int y;//variavel auxiliar da segunda lista
	int i, j;//contadores
	
	//iniciando as tabelas
	cin>>x;
	while(x>0){
		lista1.push_back(x);
		i++;
		cin>>x;
	}
	bubblesort(lista1,i);//chamando função de ordenação
	
	cin>>y;
	while(y>0){
		lista2.push_back(y);
		j++;
		cin>>y;
	}
	bubblesort(lista2,j);//chamando função de ordenação
	
	p=lista1.begin();
	u=lista2.begin();
	while(u!=lista2.end() || p!=lista1.end()){
		if(*p==*u){
			cout<<*p<<" ";
			p++;
			u++;
		}
		else if(*p<*u || u==lista2.end()){
			cout<<*p<<" ";
			p++;
		}
		else if(*p>*u || p==lista1.end()){
			cout<<*u<<" ";
			u++;
		}
	}
	//removendo os elementos inseridos
	while(!lista1.empty())
		lista1.pop_front();
	
	while(!lista2.empty())
		lista2.pop_front();
	
	return 0;
}

