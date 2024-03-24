#include<iostream>
#include<iomanip>
using namespace std;
struct dado{
	int n1, n2, n3, n4;
	double media;
};
int main(){
	dado *aluno=NULL;
	int tam;
	double soma=0;
	
	cin>>tam;
	aluno=new dado [tam];
	for(int i=0; i<tam; i++){
		cin>>aluno[i].n1>>aluno[i].n2>>aluno[i].n3>>aluno[i].n4;
	    aluno[i].media=(aluno[i].n1+aluno[i].n2+aluno[i].n3+aluno[i].n4)/4.0;
	    soma+=aluno[i].media;
	}
	cout<<fixed<<setprecision(2)<<soma/tam<<endl;
	delete[]aluno;
	return 0;
}