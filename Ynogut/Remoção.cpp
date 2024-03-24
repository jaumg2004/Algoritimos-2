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
}//fun��o auxiliar
int hash1(int k, int i, int m){
	return (hash_aux(k,m)+i)%m;
}//fun��o de sondagem
int hash_insert(dado t[], int m, int k){
	int i=0;
	int j;
	do{
		j=hash1(k,i,m);
		if(t[j].status!=1){
			t[j].k=k;
			t[j].status=1;
			return j;
		}
		else
			i++;
	}while(i!=m);
	
	return -1;
}//fun��o de inser��o
int hash_search(dado t[], int m, int k){
	int i=0;
	int j;
	do{
		j=hash1(k,i,m);
		if(t[j].k==k){
			return j;
		}
		i++;
	}while(t[j].status!=0 && i<m);
	
	return -1;
}//fun��o de busca
int hash_remove(dado t[], int m, int k){
	int j=hash_search(t,m,k);
	if(j!=-1){
		t[j].k=-1;
		t[j].status=2;
		return 0;//consegui remover
	}
	else
		return -1;//'k' n�o est� na tabela
}//fun��o de remo��o
int main(){
	
	int tam;//tamanho do vetor
	int chaves;//valores q ser�o inseridos dentro do vetor
	int procurado;//variavel que vai ser removida
	dado t[10000];//declarando struct como vetor
	
	cin>>tam;//lendo o tamanho do vetor
	
	for(int i=0; i<tam; i++){//iniciando a tabela
		t[i].k=-1;
	    t[i].status=0;
	}
	
	cin>>chaves;//inserindo as chaves
	while(chaves>0){
		hash_insert(t,tam,chaves);
		cin>>chaves;
	}
	
	cin>>procurado;//entrando com valor procurado
	
	hash_remove(t,tam, procurado);//chamando a fun��o de remo��o
	
	for(int i=0; i<tam; i++){
		cout<<t[i].k<<" ";
	}
	return 0;
}