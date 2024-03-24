#include<iostream>
#include<locale.h>
using namespace std;
int main()
{
	int v[4]={2,1,4,3};
	int x;
	int cont=0;
	
	setlocale(LC_ALL,"Portuguese");
	cin>>x;
	
	for(int i=0; i<4;i++){
		if(x==v[i])
			cont++;
	}
	
	if(cont>0)
		cout<<"x está dentro do vetor"<<endl;
	else
	{
		cout<<"x não está dentro do vetor"<<endl;
	}
	return 0;
}