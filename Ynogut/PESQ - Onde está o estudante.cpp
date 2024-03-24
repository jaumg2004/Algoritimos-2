#include<iostream>
using namespace std;
int busca(int n, int mat[], int x, int a, int b){
	int meio;
	bool achou=false;
	
	while((b<=a) && achou==false){
		meio=(a+b)/2;
		if(x<mat[meio])
			a=meio-1;
		else if(x>mat[meio])
			b=meio+1;
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
	int N, matriculas[10000], X, alto, baixo;
	int i;
	
	cin>>N;
	while(N<=1 || N>=10000){
		cin>>N;
	}
	for(i=0; i<N; i++){
		cin>>matriculas[i];
	}
	cin>>X;
	alto=i;
	baixo=0;
	if(busca(N, matriculas, X, alto, baixo)!=-1){
		cout<<"Corredor "<<busca(N, matriculas, X, alto, baixo)<<endl;
	}
	else
	{
		cout<<"Nao localizado"<<endl;
	}
	return 0;
}