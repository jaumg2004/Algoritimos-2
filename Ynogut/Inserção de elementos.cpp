#include<iostream>
using namespace std;
//struct pra armazenar os valores de um vetor
struct dado{
	int status;//0:vazio;1:preenchido
	int k;//chave
};
//fun��o auxiliar para as proximas
int hash_aux(int k, int m){
	if(k%m>0)
		return k%m;
	else
		return m+k%m;
}
//fun��o de sondagem linear
int hash1(int k, int i, int m){
	
	return (hash_aux(k,m)+i)%m;
}
//fun��o de inser��o
int hash_insert(dado t[], int m, int k){
	int i=0;//contador pro 'hash1'
	int j;//armazenador pro 'hash1'
	do{
		j=hash1(k,i,m);//armazenando 'hash1'
		//testando se a posi��o est� preenchida
		//se n�o tiver preenchida...
		if(t[j].status!=1){
			t[j].k=k;//armazenando as chaves dentro da struct
			t[j].status=1;//mudando os status
			return j;//retornando a posi��o preenchida
		}
		//se tiver...
		else
			i++;
	}while(i!=m);
	return -1;
}
int main(){
	
	dado t[10000];//declarando a struct dado
	int m;//tamanho da tabela
	int k;//chaves que ser�o inseridas
	int i;//contador do 'for'
	
	//entrada de dados
	
	cin>>m;
	for(i=0; i<m; i++){
		t[i].k=-1;
		t[i].status=0;
	}
	
	cin>>k;
	while(k!=0){//condi��o de variavel
		hash_insert(t,m,k);//chamando a fun��o de inser��o
	    cin>>k;//entrando com as chaves
	}
	
	//saida de dados
	
	for(i=0; i<m; i++)
		cout<<t[i].k<<" ";
	return 0;
}