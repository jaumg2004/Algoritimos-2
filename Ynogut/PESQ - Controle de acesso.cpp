#include<iostream>
using namespace std;
int binaria(int ids[], int procurado, int a, int b){
	int meio;
	bool achou=false;
	while((b<=a) && achou==false){
		meio=(a+b)/2;
		if(procurado<ids[meio])
			a=meio-1;
		if(procurado>ids[meio])
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
	int IDs[20],idprocurado,i=0, alto, baixo;
	
	cin>>IDs[i];
	while(IDs[i]!=-1){
		i++;
		cin>>IDs[i];
	}
	cin>>idprocurado;
	alto=i;
	baixo=0;
	
	if(binaria( IDs, idprocurado, alto, baixo)!=-1)
		cout<<"Possui acesso"<<endl;
	else
	{
		cout<<"Nao possui acesso"<<endl;
	}
	return 0;
}