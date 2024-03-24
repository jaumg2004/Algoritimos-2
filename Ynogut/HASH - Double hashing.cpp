#include<iostream>
using namespace std;
int h1(int k, int m){
	if(k%m>0)
		return k%m;
	else
		return m+k%m;
}
int h2(int k, int m){
	if(1+(k%(m-1))>0)
		return 1+(k%(m-1));
	else
		return m+1+(k%(m-1));
}
int dhash(int k, int m, int i){
	return (h1(k, m)+i*h2(k, m))%m;
}
int main()
{
	int k, m;
	
	cin>>k>>m;
	for(int i=0; i<m; i++){
		cout<<dhash(k,m,i)<<" ";
	}
	
	return 0;
}