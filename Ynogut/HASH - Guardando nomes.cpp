#include<iostream>
#include<cstring>
using namespace std;
struct dado{
	int status, k;
	char info[50];
};
int h1(int k, int m){
	if(k%m>0)
		return k%m;
	else
		return m+k%m;
}
int h2(int k, int m){
	if(1+(k%(m-1))>0)
		return 1+(k%(m-1));
	else
		return m+1+(k%(m-1));
}
int dhash(int k, int m, int i){
	return (h1(k, m)+i*h2(k, m))%m;
}
int hash_insert(dado t[], int m, int k, char nome[]){
	int i=0, l;
	do{
		l=dhash(k,m,i);
		if(t[l].status!=1){
			t[l].k=k;
			t[l].status=1;
			strcpy(t[l].info, nome);
			return l;
		}
		else
		{
			i++;
		}
	}while(i!=m);
	return -1;
}
int hash_search(dado t[], int m, int k){
	int i=0;
	int j;
	do{
		j=dhash(k,m,i);
		if(t[j].k==k)
			return j;
		i++;
	}while(t[j].status!=0 && i<m);
	return -1;
}
int hash_remove(dado t[], int m, int k){
	int j;
	j=hash_search(t,m,k);
	if(j!=-1){
		t[j].status=2;
		t[j].k=-1;
		strcpy(t[j].info,"vazio");
		return 0;
	}
	else
		return -1;
}
int main()
{
	int m, aux, chave, M;
	char nome[50];
	dado T[1000];
	
	cin>>m;
	
	for(int j=0; j<m; j++){
		T[j].k=-1;
		T[j].status=0;
		strcpy(T[j].info,"vazio");
	}
	cin>>M;
	while(M!=5){
		switch(M){
			case 1:
				aux=0;
				cin.ignore();
				cin.getline(nome, 50);
				for(int i=0; i<strlen(nome); i++){
					aux=aux+nome[i];
				}
                hash_insert(T, m, aux, nome);
                break;
            case 2:
            	aux=0;
            	cin.ignore();
            	cin.getline(nome,50);
            	for(int i=0; i<strlen(nome); i++){
					aux=aux+nome[i];
				}
	            if(hash_search(T,m,aux)!=-1)
	            	cout<<nome<<" encontrado na posicao "<<hash_search(T,m,aux)<<endl;  
	            else
	            	cout<<nome<<" nao encontrado"<<endl;
	        	break;
	        case 3:
	        	aux=0;
            	cin.ignore();
            	cin.getline(nome,50);
            	for(int i=0; i<strlen(nome); i++){
					aux=aux+nome[i];
				}
	        	hash_remove(T,m,aux);
	        	break;
	        case 4:
	        	for(int i=0; i<m; i++){
				cout<<T[i].info<<endl;
				}
				break;
		}
		cin>>M;	
	}
	
	return 0;
}