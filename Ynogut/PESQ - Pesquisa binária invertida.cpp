#include<iostream>
using namespace std;
int busca(int n, int v[], int x, int a, int b){
	
	bool achou=false;
	int meio;
	while((b>=a) && achou==false){
		meio=(a+b)/2;
		if(x>v[meio]){
			a=meio+1;
		}
		else if(x<v[meio]){
			b=meio-1;
		}
		else
		{
			achou=true;
		}
	}
	if(achou)
		return meio;
	else
	{
		return -1;
	}
}
int main()
{
	int N, vet[10000], X, alto, baixo;
	int i;
	
	cin>>N;
	while(N<=1 || N>=10000){
		cin>>N;
	}
	for(i=0; i<N; i++){
		cin>>vet[i];
	}
	baixo=N-1;
	alto=0;
	cin>>X;
	if(busca(N, vet, X, alto, baixo)!=-1)
		cout<<X<<" encontrado na posicao "<<busca(N, vet, X, alto, baixo)<<endl;
	else
	{
		cout<<X<<" nao encontrado"<<endl;
	}
	return 0;
}