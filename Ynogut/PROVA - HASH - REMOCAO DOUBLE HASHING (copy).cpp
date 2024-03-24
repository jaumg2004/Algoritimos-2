#include<iostream>
using namespace std;
struct dado{
  int k;//chaves
  int status;//0:vazio-1:preenchido-2:removido
};
int hash1(int k, int m){
    if(k%m>0){
        return k%m;
    }
    else{
        return m+k%m;
    }
}//primeira função auxiliar
int hash2(int k, int m){
    if(1+k%(m-1)>0){
        return 1+k%(m-1);
    }
    else{
        return m+1+k%(m-1);
    }
}//segunda função auxiliar
int dhash(int k, int i, int m){
    
    //chamando as funções auxiliares e retornando um valor
    return (hash1(k,m)+hash2(k,m)*i)%m;
    
}//função de double hashing
int hash_insert(dado t[], int m, int k){
    int i=0;//contador
    int j;//variavel que vai ser armazenado o 'dhash'
    
    do{
        j=dhash(k,i,m);
        if(t[j].status!=1){
            t[j].k=k;
            t[j].status=1;
            return j;
        }
        else{
            i++;
        }
    }while(i!=m);
    
    return -1;
}//função de inserção
int hash_search(dado t[], int m, int k){
    int i=0;//contador
    int j;//variavel que vai ser armazenado o 'dhash'
    
    do{
        j=dhash(k,i,m);
        if(t[j].k==k){
            return j;
        }
        i++;
    }while(t[j].status!=0 && i<m);
    
    return -1;
}//função de busca
int hash_remove(dado t[], int m, int k){
    int j=hash_search(t,m,k);//recebendo a função de busca
    
    if(j!=-1){
        t[j].k=-1;
        t[j].status=2;
        return 0;//removido
    }
    else{
        return -1;//chave não existe
    }
}//função de remoção
int main(){
    
    int i;//contador
    int tam;//tamanho do vetor
    int chaves;//variaveis que serão inseridas no vetor
    int procurado;//variavel que vai ser buscada
    dado t[100];//declarando struct como um vetor
    
    cin>>tam;//lendo o tamanho do vetor
    
    while(tam>=100){//condição de variavel do tamanho
        cin>>tam;
    }
    
    for(i=0; i<tam; i++){//inciando a tabela
        t[i].k=-1;
        t[i].status=0;
    }
    
    cin>>chaves;//entrando com as chaves
    
    while(chaves>0){//condição de variavel das chaves
        hash_insert(t,tam,chaves);//chamando a função de inserção
        cin>>chaves;
    }
    
    cin>>procurado;//lendo a variavel que vai ser buscada
    
    hash_remove(t,tam,procurado);//chamando a função de remoção
    
    //mostrando as chaves
    for(i=0; i<tam; i++){
        cout<<t[i].k<<" ";
    }
    
    return 0;
}