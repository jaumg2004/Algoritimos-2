#include<iostream>
using namespace std;
//struct pra armazenar dados de um vetor
struct dado{
	int k;//chaves
	int status;//0:vazio, 1;preenchido
};
//fun��o auxiliar
int hash_aux(int k, int m){
	if(k%m>0)
		return k%m;
	else
		return m+k%m;
}
//fun��o de sondagem linear que recebe a fun��o auxiliar
int hash1(int k, int i, int m){
	return (hash_aux(k,m)+i)%m;                  
}
//fun��o de inser��o
int hash_insert(dado T[], int m, int k){
	int i=0;
	int j;
	
	do{
		j=hash1(k,i,m);
		if(T[j].status!=1){
			T[j].k=k;
		    T[j].status=1;
		    return j;
		}
		else
			i++;
	}while(i!=m); 
	return -1;
}
//fun��o de busca
int hash_search(dado T[], int m, int k){
	int i=0;
	int j;
	
	do{
		j=hash1(k,i,m);
		if(T[j].k==k){
			return j;
		}
		i++;
	}while(T[j].status!=0 && i<m);
	return -1;                              
}
int main(){
	
	int procurado;//variavel que vai ser procurada
	int chave;//valores que v�o ser armazenados dentro de um vetor
	int tam;//tamanho do vetor
	int i;//contador
	dado t[10000];//declarando a struct como um vetor
	
	
	cin>>tam;//lendo o tamanho do vetor
	
	for(i=0; i<tam; i++){//inicilizando a tabela
		t[i].k=-1;
		t[i].status=0;          
	}
	
	cin>>chave;//entrando com as chaves
	
	while(chave>0){//condi��o de variavel
		hash_insert(t,tam,chave);//chamando a fun��o de inser��o       
		cin>>chave;       
	}
	
	cin>>procurado;//entrando com a variavel que vai ser procurada
	
	if(hash_search(t,tam,procurado)!=-1){//chamando a fun��o de busca e comparando
		cout<<"Chave "<<procurado<<" encontrado na posi��o "<<hash_search(t,tam,procurado);
	}
	else{                            
		cout<<"Chave "<<procurado<<" n�o encontrado";
	}
	return 0;
}