#include<iostream>
using namespace std;
struct dado{
	int k;//chaves
	int status;//0:vazio, 1:preenchido, 2:removido
};
int hash_aux(int k, int m){
	if(k%m>0)
		return k%m;
	else
		return m+k%m;
}//função auxiliar
int hash1(int k, int i, int m, int c1, int c2){
	return (hash_aux(k,m)+c1*i+c2*i*i)%m;
}//função de sondagem quadratica
int hash_insert(dado t[], int m, int k, int c1, int c2){
	int i=0;
	int j;
	
	do{
		j=hash1(k,i,m,c1,c2);
		if(t[j].status!=1){
			t[j].k=k;
			t[j].status=1;
			return j;
		}
		else
			i++;
	}while(i!=m);
	
	return -1;
}//função de inserção
int hash_search(dado t[], int m, int k, int c1, int c2){
	int i=0;
	int j;
	
	do{
		j=hash1(k,i,m,c1,c2);
		if(t[j].k==k)
			return j;
		i++;
	}while(t[j].status!=0 && i<m);
	
	return -1;
}//função de busca
int hash_remove(dado t[], int m, int k, int c1, int c2){
	int i=0;
	int j;
	
	j=hash_search(t,m,k,c1,c2);
	if(j!=-1){
		t[j].k=-1;
		t[j].status=2;
		return 0;
	}
	else
		return -1;
}//função de remoção
int main(){
	
	int tam;//tamanho do vetor
	int c1, c2;//variaveis auxiliares
	int chaves;//valores que serão inseridos no vetor
	int procurado;//variavel q vai ser buscada
	dado t[10000];//declarando struct como vetor
	
	cin>>tam>>c1>>c2;//lendo o tamanho do vetor e dos auxiliares
	
	for(int i=0; i<tam; i++){//iniciando a tabela
		t[i].k=-1;
	    t[i].status=0;
	}
	
	cin>>chaves;//entrando com os valores
	while(chaves>0){
		hash_insert(t,tam,chaves,c1,c2);//chamando a função de inserção
		cin>>chaves;
	}
	
	cin>>procurado;//lendo o valor procurado
	
	hash_remove(t,tam,procurado,c1,c2);//chamando a função de remoção
	
	for(int i=0; i<tam; i++){
		cout<<t[i].k<<" ";
	}
	return 0;
}