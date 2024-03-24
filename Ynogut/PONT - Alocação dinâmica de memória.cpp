#include<iostream>
#include<iomanip>
using namespace std;
struct dado{
	int n1, n2, n3, n4;
	double media;
};
int main(){
	dado *aluno=NULL;
	
	aluno=new dado;
	
	cin>>aluno->n1>>aluno->n2>>aluno->n3>>aluno->n4;
	aluno->media=(aluno->n1+aluno->n2+aluno->n3+aluno->n4)/4.0;
	cout<<fixed<<setprecision(2)<<aluno->media<<endl;
	
	return 0;
}