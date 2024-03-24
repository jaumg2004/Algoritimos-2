#include<iostream>
#include<iomanip>
using namespace std;
struct dado{
	int n1,n2,n3,n4;//notas dos alunos
};
int main(){
	
	dado *aluno=NULL;//declarando struct como ponteiro
	double soma=0;//somatorio das medias
	int n;//número de alunos
	int i;//contador
	
	cin>>n;//entrando com o número de alunos
	
	aluno=new dado [n];//varivel vetor do ponteiro
	
	//entrando com as notas
	for(i=0;i<n;i++){
		cin>>aluno[i].n1>>aluno[i].n2>>aluno[i].n3>>aluno[i].n4;
		soma=(aluno[i].n1+aluno[i].n2+aluno[i].n3+aluno[i].n4)/4.0;
	}
	
	//media das medias
	cout<<fixed<<setprecision(2)<<soma/n<<endl;
	
	delete[]aluno;
	return 0;
}