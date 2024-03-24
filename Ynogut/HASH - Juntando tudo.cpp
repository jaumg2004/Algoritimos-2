#include<iostream>
using namespace std;
struct dado{
	int status, k;
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
int hash_insert(dado t[], int m, int k){
	int i=0, l;
	do{
		l=dhash(k,m,i);
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
		return 0;
	}
	else
		return -1;
}
int main(){
	int m, aux, chave, M;
	dado T[1000];
	
	cin>>m;
	
	for(int j=0; j<m; j++){
		T[j].k=-1;
		T[j].status=0;
	}
	cin>>M;
	while(M!=5){
		switch(M){
			case 1:
				cin>>aux;
                hash_insert(T, m, aux);
                break;
            case 2:
            	cin>>chave;
	            if(hash_search(T,m,chave)!=-1)
	            	cout<<hash_search(T,m,chave)<<endl;  
	            else
	            	cout<<"-1"<<endl;
	        	break;
	        case 3:
	        	cin>>chave;
	        	hash_remove(T,m,chave);
	        	break;
	        case 4:
	        	for(int i=0; i<m; i++){
				cout<<T[i].k<<" ";
				}
				cout<<endl;
				break;
		}
		cin>>M;	
	}
	
	return 0;
}