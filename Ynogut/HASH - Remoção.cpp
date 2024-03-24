#include<iostream>
using namespace std;
struct dado{
	int status, k;
};
int hash_aux(int k, int m){
	if(k%m<0)
		return m+k%m;
	else
		return k%m;
}
int hash1(int k, int i, int m){
	return (hash_aux(k, m)+i)%m;
}
int hash_insert(dado t[], int m, int k){
	int i=0, l;
	do{
		l=hash1(k,i,m);
		if(t[l].status!=1){
			t[l].k=k;
			t[l].status=1;
			return l;
		}
		else
			i++;
	}while(i!=m);
	return -1;
}
int hash_search(dado t[], int m, int k){
	int i=0;
	int j;
	do{
		j=hash1(k,i,m);
		if(t[j].k==k)
			return j;
		i++;
	}while(t[j].status!=0 && i<m);
	return -1;
}
int hash_remove(dado t[], int m, int k){
	int j=hash_search(t,m,k);
	if(j!=-1){
		t[j].status=2;
		t[j].k=-1;
		return 0;
	}
	else
		return -1;
}
int main(){
	int m, aux, chave;
	dado T[1000];
	
	cin>>m;
	for(int j=0; j<m; j++){
		T[j].k=-1;
		T[j].status=0;
	}
	cin>>aux;
	while(aux>0){
		hash_insert(T,m,aux);
		cin>>aux;
	}
	cin>>chave;
	hash_remove(T,m,chave);
	for(int i=0; i<m; i++){
		cout<<T[i].k<<" ";
	}
	return 0;
}