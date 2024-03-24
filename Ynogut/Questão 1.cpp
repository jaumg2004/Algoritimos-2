#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double x, y, z;
	
	cin>>x;
	z=1+pow(x,2);
	y=sqrt(1/z);
	cout<<fixed<<setprecision(4)<<"y = "<<y<<endl;
	return 0;
}