#include<iostream>
using namespace std;
int mod(int x, int y){
     if(x>y){
        return mod(x-y,y);
    }
    if(x<y){
        return x;
    }
    if(x==y){
        return 0;
    }
}//fun��o restante
 int main(){
     int x,y;//variaveis que ser�o utilizadas na fun��o
     
     cin>>x>>y;//entrando com as variaveis
     
     while(x!=-1 && y!=-1){//condi��o de variaveis
         cout<<mod(x,y)<<endl;//chamando a fun��o de restante e mostrando os valores
         cin>>x>>y;
     }
    return 0;
}