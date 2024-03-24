#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct info{
    char nome[100];
    int idade;
    float peso;
    float altura; 
};
struct dado{
	int status, k;
	info atleta;
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
			strcpy(t[l].atleta.nome, nome);
			cin>>t[l].atleta.idade>>t[l].atleta.peso>>t[l].atleta.altura;
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
		strcpy(t[j].atleta.nome,"vazio");
		t[j].atleta.idade=0;
		t[j].atleta.peso=0;
		t[j].atleta.altura=0;
		return 0;
	}
	else
		return -1;
}
int main()
{
	int m, aux, chave, M, arm;
	char nome[50];
	dado T[1000];
	
	cin>>m;
	
	for(int j=0; j<m; j++){
		T[j].k=-1;
		T[j].status=0;
		strcpy(T[j].atleta.nome,"vazio");
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
	            if(hash_search(T,m,aux)!=-1){
	            	arm=hash_search(T,m,aux);
					cout<<"Nome: "<<T[arm].atleta.nome<<endl;
					cout<<"Idade: "<<T[arm].atleta.idade<<endl;
					cout<<fixed<<setprecision(1)<<"Peso: "<<T[arm].atleta.peso<<endl;
					cout<<fixed<<setprecision(2)<<"Altura: "<<T[arm].atleta.altura<<endl;
					cout<<"\n";
				}
	            	  
	            else{
					cout<<nome<<" nao encontrado"<<endl;
					cout<<"\n";
				}
	            	
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
	        		if(T[i].status==1){
						cout<<"Nome: "<<T[i].atleta.nome<<endl;
                        cout<<"Idade: "<<T[i].atleta.idade<<endl;
				        cout<<fixed<<setprecision(1)<<"Peso: "<<T[i].atleta.peso<<endl;
				        cout<<fixed<<setprecision(2)<<"Altura: "<<T[i].atleta.altura<<endl;
				        cout<<"\n";
					}
				}
				break;
		}
		cin>>M;	
	}
	
	return 0;
}