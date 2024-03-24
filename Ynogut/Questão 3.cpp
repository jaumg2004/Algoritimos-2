#include<iostream>
using namespace std;
int main()
{
	int maior=-99999, n, V[100000];
	
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>V[i];
	for(int j=0; j<n; j++){
		if(V[j]%2==0 && V[j]>maior)
			maior=V[j];
	}
	cout<<maior;
	return 0;
}