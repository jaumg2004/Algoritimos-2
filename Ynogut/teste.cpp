#include <iostream>
#include <cstring>
struct dados{
	string nome;
	int matricula;
};
void binaria(dados aluno[], char vetor[], int tamanho)
{
	bool achou; // var aux p/ busca
	int baixo, meio, alto; // var aux
	baixo = 0;
	alto = tamanho - 1;
	achou = false;
	while ((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if (x < vetor[meio])
			alto = meio - 1;
		else if (x > vetor[meio])
			baixo = meio + 1;
		else
			achou = true;
	}
	if (achou)
		return meio;
	else
		return -1;
}
int main()
{
	string procurado, nomencontrado[51], cursoencontrado[51];
	int cont=0, matencontrada, N;
	dados aluno[10000];

	cin.getline(aluno[cont].nome,51);
	while(strcmp(aluno[cont].nome,"fim")!=0){
         cin.ignore();
         cin>>aluno[cont].matricula;
         cont++;
         cin.getline(aluno[cont].nome,51);
	}
	cin.ignore();
	cin.getline(procurado, 51);
	void binaria(aluno, procurado, cont);
	return 0;
}