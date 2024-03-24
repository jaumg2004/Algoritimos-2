#include<iostream>
using namespace std;
int main()
{
	int x, vetor[100], pos, cont=0;
	int i=0;
	
	cin>>vetor[i];
	while(vetor[i]!=-1){
		i++;
		cin>>vetor[i];
	}
	cin>>x;
	for(int j=0;j<=i;j++){
		if(x==vetor[j]){
			cont++;
			pos=j;
		}
	}
	if(cont==0){
		cout<<x<<" nao encontrado"<<endl;
	}
	else
	{
		cout<<x<<" encontrado na posicao "<<pos<<endl;
	}
	
	return 0;
}