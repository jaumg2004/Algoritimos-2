#include<iostream>
using namespace std;
struct dado{
	int k;//chaves
	int status;//0:vazio, 1:preenchido, 2:removido
};
int hash1(int k, int m){
	if(k%m>0)
		return k%m;
	else
		return m+k%m;
}//primeira função auxiliar
int hash2(int k, int i, int m){
	if(1+k%(m-1)>0)
		return 1+k%(m-1);
	else
		return m+1+k%(m-1);
}//segunda função auxiliar
int dhash(int k, int i, int m){
	return (hash1(k,m)+i*hash2(k,i,m))%m;
}//função double hashing
int hash_insert(dado t[], int m, int k){
	int i=0;
	int j;
	do{
		j=dhash(k,i,m);
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
int hash_search(dado t[], int m, int k){
	int i=0;
	int j;
	do{
		j=dhash(k,i,m);
		if(t[j].k==k)
			return j;
		i++;
	}while(t[j].status!=0 && i<m);
	
	return -1;
}
int hash_remove(dado t[], int m, int k){
	int j=hash_remove(t,m,k);
	
	if(j!=-1){
		t[j].k=-1;
		t[j].status=2;
		return 0;//consegui remover
	}
	return -1;//'k' não está no vetor
}
int main(){
	
	int x;//opção do menu
	int tam;//tamanho do vetor
	int chaves;//valores que serão utilizados
	dado t[10000];//declarando struct como vetor
	
	cin>>tam;//lendo o tamanho do vetor
	
	//iniciando a tabela
	for(int i=0; i<tam; i++){
		t[i].k=-1;
		t[i].status=0;
	}
	
	//entrando com o menu
	cin>>x;
	
	while(x!=5){
		switch(x){
			case 1:
				cin>>chaves;
				hash_insert(t,tam,chaves);
				break;
			case 2:
				cin>>chaves;
				if(hash_search(t,tam,chaves)!=-1){
					cout<<hash_search(t,tam,chaves)<<endl;
				}
				else
					cout<<"-1"<<endl;
				break;
			case 3:
				cin>>chaves;
				hash_remove(t,tam,chaves);
				break;
			case 4:
				for(int i=0; i<tam; i++){
					cout<<t[i].k<<" ";
				}
				cout<<endl;
				break;	
	    }
	    cin>>x;
	}
	
	return 0;
}