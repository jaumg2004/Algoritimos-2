#include<iostream>
using namespace std;
int hash_aux(int k, int m){
	if(k%m<0)
		return m+(k%m);
	else
	{
		return k%m;
	}
}
int hash2(int k, int i, int m, int c1, int c2){
	return (hash_aux(k,m)+c1*i+c2*i*i)%m;
}
int main()
{
	int k, m, c1, c2;
	
	cin>>k>>m>>c1>>c2;
	for(int i=0; i<m; i++){
		cout<<hash2(k,i,m,c1,c2)<<" ";
	}
	
	return 0;
}