#include<iostream>
#include<cstring>
using namespace std;
struct dados{
	
	char nome[51], curso[51];
	int matricula;
}aluno[10000];
int main()
{
	char procurado[51], nomencontrado[51], cursoencontrado[51];
	int cont=0, matencontrada, N;
	
	cin>>N;
	while(N<=1 || N>=10000){
		cin>>N;
	}
	for(int i=0; i<N; i++){
		cin.ignore();
		cin.getline(aluno[i].nome, 51);
		cin.getline(aluno[i].curso, 51);
		cin>>aluno[i].matricula;
	}
	cin.ignore();
	cin.getline(procurado, 51);
	for(int j=0; j<N; j++){
		if(strcmp(procurado, aluno[j].nome)==0){
			cont++;
			strcpy(nomencontrado, aluno[j].nome);
			strcpy(cursoencontrado, aluno[j].curso);
			matencontrada=aluno[j].matricula;
		}
	}
	if(cont>0){
		cout<<nomencontrado<<endl;
		cout<<cursoencontrado<<endl;
		cout<<matencontrada<<endl;
	}
	else
	{
		cout<<"Aluno nao localizado";
	}
	return 0;
}