#include<iostream>
#include<iomanip>
using namespace std;
struct dado{
	int n1,n2,n3,n4;//notas do aluno
};
int main(){
	
	dado *aluno=NULL;//declarando ponteiro
	
	aluno=new dado;//declarando variavel do ponteiro
	
	//entrando com as notas
	cin>>aluno->n1>>aluno->n2>>aluno->n3>>aluno->n4;
	
	//calculando a media final
	cout<<fixed<<setprecision(2)<<(aluno->n1+aluno->n2+aluno->n3+aluno->n4)/4.0;
	
	return 0;
}