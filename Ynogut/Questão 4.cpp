#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i=0,X;
	double soma=0;
	
	cin>>X;
	while(X!=0){
		i++;
		soma+=X;
		cin>>X;
	}
	cout<<fixed<<setprecision(2)<<soma/i<<endl;
	return 0;
}