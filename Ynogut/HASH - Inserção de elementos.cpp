#include<iostream>
using namespace std;
struct dado{
	int status, k;
};
int hash_aux(int k, int m){
	if(k%m<0)
		return m+(k%m);
	else{
		return k%m;
	}
}
int hash1(int k, int i, int m){
	return (hash_aux(k,m)+i)%m;
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
		{
			i++;
		}
	}while(i!=m);
	return -1;
}
int main(){
	int m, aux;
	dado T[1000];
	
	cin>>m;
	
	for(int j=0; j<m; j++){
		T[j].k=-1;
		T[j].status=0;
	}
	cin>>aux;
	while(aux>0){
		hash_insert(T, m, aux);
		cin>>aux;
	}
	for(int o=0; o<m; o++){
		cout<<T[o].k<<" ";
	}
	
	return 0;
}