#include<iostream>
using namespace std;
//primeira funcao auxiliar para o 'double hash'
int hash1(int k, int m){
	if(k%m>0)
		return k%m;
	else
		return m+k%m;
}
//segunda funcao auxiliar para o 'double hash'
int hash2(int k, int m){
	if(1+k%(m-1)>0)
		return 1+k%(m-1);
	else
		return m+1+k%(m-1);
}
//funcao double
int dhash(int k, int m, int i){
	
	return (hash1(k,m)+hash2(k,m)*i)%m;
}
int main(){
	
	int k;//chave principal
	int m;//tamanho da tabela
	int i;//contador da tabela
	
	//entrada de dados
	
	cin>>k>>m;
	
	//chamando e mostrando double hash
	
	for(i=0; i<m; i++){
		cout<<dhash(k,m,i)<<" ";
	}
	return 0;
}