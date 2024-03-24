#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double raiz(double x, double x0, double e){
	if(abs(x0*x0-x)<=e)
		return x0;
	else
		return raiz(x, (x0*x0+x)/(2*x0), e);
}
int main()
{
	double x, x0, e;
	
	cin>>x;
	while(x<0)
		cin>>x;
	cin>>x0;
	while(x0<0)
		cin>>x0;
	cin>>e;
	while(e<0)
		cin>>e;
	cout<<fixed<<setprecision(4)<<raiz(x, x0, e);
	return 0;
}